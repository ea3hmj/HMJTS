/*
	EEprom.cpp 1.0 
	Copyright (C) EA3HMJ 01-2021

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
		
	* 	For Arduino IDE , SMT32F103
	*
	*	
	*	TODO
	*
 */
#include <arduino.h>
#include <math.h>
#include "eeprom.h"

EEprom::EEprom()
{

}
float EEprom::readFLOAT(int pos){
	myFloat	tmp_float;
	for (int ii = 0; ii < 4; ii++)
	{
		tmp_float.Byte[ii] = EEPROM.read(10+ (pos )+  ii);       
	};
	return tmp_float.Float;
}
void EEprom::writeFLOAT(int pos,float f){
	myFloat	tmp_float;
	tmp_float.Float=f;
	for (int ii = 0; ii < 4; ii++)
	{
		EEPROM.write(10 + (pos ) + ii, tmp_float.Byte[ii]);  
	};
}

int EEprom::readINT(int pos){
	byte lowByte = EEPROM.read(10+pos);
    byte highByte = EEPROM.read(10+pos + 1);

    return (int)((lowByte << 0) & 0xFF) + ((highByte << 8) & 0xFF00);
}

void EEprom::writeINT(int pos,int f){
    byte lowByte = ((f >> 0) & 0xFF);
    byte highByte = ((f >> 8) & 0xFF);

    EEPROM.write(10+pos, lowByte);
    EEPROM.write(10+pos + 1, highByte);
}

byte EEprom::readBYTE(int pos){
	byte lowByte = EEPROM.read(10+pos);
    return lowByte ;
}

void EEprom::writeBYTE(int pos,byte f){
    byte lowByte = f;
    EEPROM.write(10+pos, lowByte);
}
