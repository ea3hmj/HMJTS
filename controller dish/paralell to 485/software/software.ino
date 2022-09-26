/*
	Encoder_modbus-rtu - Manejo encoder paralelo y serie por rs-485 y modbus rtu
	Tambien se puede usar con paralelo solo configurando el numero de SLAVES a 1
	
	https://github.com/yaacov/ArduinoModbusSlave
	Copyright (C) EA3HMJ 08-2022

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
*/
#include "src/ModbusSlave.h"
#include "src/eeprom.h"
#define ledPin  			PC13 // onboard led 
#define NUMBER_OF_SLAVES 	1
#define ID_SLAVE_1 			1
#define ID_SLAVE_2 			2

#define SERIAL_BAUDRATE 115200 // Change to the baudrate you want to use for Modbus communication.
#define SERIAL_PORT Serial2   // Serial port to use for RS485 communication, change to the port you're using.
enum class Type {PARALELO,SERIE};

namespace Paralelo{
	enum Map{     
		// The first register starts at address 0
		POSITION,			// R0
		NONE0,
		NONE1,				
		NONE2,
		ADDR,				// R4
		SPEED,				// R5
		BITS,				// R6				
		NONE3,				
		GRAY,				// R8
		DIR,				// R9
		// leave this one
		TOTAL_REGS_SIZE   // total number of registers for function 3 and 16 share the same register array
	};
	// encoder paralelo
	uint16 			addr=1;
	uint16 			speed=4;
	uint16 			dir=0;
	uint16 			gray=1;
	uint16 			turn=0;
	uint16 			EncoderBits=13;
	uint16			EncoderResolucion;
	////////////////////////////////////////////////////////////
	
	////////////////////////////////////////////////////////////
	long SelSpeed(uint16 p){
		if (p==0)
			return 9600;
		else if (p==1)
			return 19200;
		else if (p==2)
			return 38400;
		else if (p==3)
			return 57600;
		else if (p==4)
			return 115200;
		// default
		return 115200;
	}
	// Configurar encoder
	void ConfigEncoder(uint16 bits){
		EncoderResolucion=pow(2,bits);
	}
	// Leer en encoder modbus
	 uint16 ReadEncoder(){
		// leemos el encoder
		uint16 num;
		num= GPIOB->regs->IDR & 0x01fff;
		if (gray){
			num = (num ^(num>>8));
			num = (num ^(num>>4));
			num = (num ^(num>>2));
			num = (num ^(num>>1));
			num&= 0x01fff;
		}
		// giro CW o CCW
		return num;//(dir?num:(0x1fff-num)); 
	}
	// determina la posicion del encoder en funcion de la resolucion y multiplicacion
	uint16  ReadPositionEncoder(){
		uint16 tmp;
		tmp=ReadEncoder();
		if (dir)
			return (EncoderResolucion-1-tmp);
		else
			return tmp;
	}
}
#if NUMBER_OF_SLAVES==2
namespace Serie{
	#define SERIAL_INC	Serial1
	enum Map{     
		// The first register starts at address 0
		NONE0,
		NONE1,
		NONE2,
		NONE3,				
		ENCODERH,			// R4
		ENCODERL,			// R5
		TEMPERATURE,		// R6				
		FILTER,				// R3
		ADDR,				// R4
		SPEED,				// R5
		// leave this one
		TOTAL_REGS_SIZE   // total number of registers for function 3 and 16 share the same register array
	};
	uint16 			addr=2;
	uint16 			speed=7;	//115200
	// encoder serie
	uint16 			temperature;
	uint16 			filter=3;	// 0.5Hz

	////////////////////////////////////////////////////////////
	long SelSpeed(uint16 p){
		if (p==1)
			return 2400;
		else if (p==2)
			return 4800;
		else if (p==3)
			return 9600;
		else if (p==4)
			return 19200;
		else if (p==5)
			return 38400;
		else if (p==6)
			return 57200;
		else if (p==7)
			return 115200;
		// default
		return 115200;
	}	
	// Leer en encoder modbus
	 uint32 ReadEncoder(){
		static uint32  lastPos=0;
		static uint32  actualPos=0;
		myUint32 pos;
		int ret;
		// leemos el encoder
		SERIAL_INC.print("get-360");
		SERIAL_INC.flush();
		delay(20);
		
		if (SERIAL_INC.available()) {
			ret=SERIAL_INC.readBytes(pos.Byte,4);
			if (ret!=4)
				return lastPos; 
			lastPos=actualPos=pos.UINT32;
	/*		Serial.print(pos.Byte[0],HEX);
			Serial.print(" ");
			Serial.print(pos.Byte[1],HEX);
			Serial.print(" ");
			Serial.print(pos.Byte[2],HEX);
			Serial.print(" ");
			Serial.println(pos.Byte[3],HEX);
	*/		return actualPos;
		}
		return lastPos; 
	}
}
#endif
EEprom			config;
myUint32 		pos;
bool			update1=false;
bool			update2=false;
bool			inclinometro=false;
////////////////////////////////////////////////////////////
void ActualizaCambios(uint16 *holdingRegs,uint16 pos,uint16  *para,uint16 posEE){
	if (holdingRegs[pos]!=*para){
		*para=holdingRegs[pos];
		config.writeBYTE(posEE,(byte)*para);
	}
}
////////////////////////////////////////////////////////////
uint16_t memory_slave1[Paralelo::Map::TOTAL_REGS_SIZE];
#if NUMBER_OF_SLAVES==2
uint16_t memory_slave2[Serie::Map::TOTAL_REGS_SIZE];
#endif
// You shouldn't have to change anything below this to get this example to work
uint8_t memory_slave1_size = sizeof(memory_slave1) / sizeof(memory_slave1[0]); // Get the size of the input_pins array
#if NUMBER_OF_SLAVES==2
uint8_t memory_slave2_size = sizeof(memory_slave2) / sizeof(memory_slave2[0]); // Get the size of the output_pins array
#endif
// Initialize an array of slaves.
#if NUMBER_OF_SLAVES==1
ModbusSlave slaves[NUMBER_OF_SLAVES] = {ModbusSlave(ID_SLAVE_1)};
#else
ModbusSlave slaves[NUMBER_OF_SLAVES] = {ModbusSlave(ID_SLAVE_1), ModbusSlave(ID_SLAVE_2)};
#endif
// Create an Modbus Object and pass the array of slaves.
Modbus modbus(SERIAL_PORT, slaves, NUMBER_OF_SLAVES);
void setup()
{
	afio_cfg_debug_ports(AFIO_DEBUG_SW_ONLY);                                                                 // Se deshabilitan los pines JTAG, pero se permiten los pines para ST-LINK
	delay(2000);
	// port B como entrada
	GPIOB->regs->CRL =0x88888888;
	GPIOB->regs->CRH =0x88888888; 
	GPIOB->regs->ODR =0xFFFFFFFF; 	
	digitalWrite(ledPin,HIGH);	
	
	if (config.readBYTE(0)==0x81){
		Paralelo::addr=config.readBYTE(1);
		Paralelo::speed=config.readBYTE(2);
		Paralelo::dir=config.readBYTE(3);
		Paralelo::gray=config.readBYTE(4);
		Paralelo::EncoderBits=config.readBYTE(6);
	}else{
		config.writeBYTE(0,0x81);
		config.writeBYTE(1,(byte)Paralelo::addr);
		config.writeBYTE(2,(byte)Paralelo::speed);
		config.writeBYTE(3,(byte)Paralelo::dir);
		config.writeBYTE(4,(byte)Paralelo::gray);
		config.writeBYTE(6,(byte)Paralelo::EncoderBits);
	}
    memory_slave1[Paralelo::Map::ADDR]=Paralelo::addr;
    memory_slave1[Paralelo::Map::SPEED]=Paralelo::speed;
	memory_slave1[Paralelo::Map::DIR]=Paralelo::dir;
	memory_slave1[Paralelo::Map::GRAY]=Paralelo::gray;
	memory_slave1[Paralelo::Map::BITS]=Paralelo::EncoderBits;
	// por si hay algo raro, se soluciono al iniciar la funcion ReadPositionEncoder
	Paralelo::ConfigEncoder(Paralelo::EncoderBits);
#if NUMBER_OF_SLAVES==2
 	if (config.readBYTE(100)==0x80){
		Serie::addr=config.readBYTE(101);
		Serie::speed=config.readBYTE(102);
		Serie::filter=config.readBYTE(103);
	}else{
		config.writeBYTE(100,0x80);
		config.writeBYTE(101,(byte)Serie::addr);
		config.writeBYTE(102,(byte)Serie::speed);
		config.writeBYTE(103,(byte)Serie::filter);
	}
    memory_slave2[Serie::Map::ADDR]=Serie::addr;
    memory_slave2[Serie::Map::SPEED]=Serie::speed;
	memory_slave2[Serie::Map::FILTER]=Serie::filter;
	// inicializamos comunicacion con encoder
	SERIAL_INC.begin(115200);
	SERIAL_INC.setTimeout(100);
	delay(200);
#endif	
    // Register functions to call when a certain function code is received.
    slaves[0].cbVector[CB_READ_HOLDING_REGISTERS] = readMemorySlave1;
    slaves[0].cbVector[CB_WRITE_HOLDING_REGISTERS] = writeMemorySlave1;
#if NUMBER_OF_SLAVES==2
		slaves[1].cbVector[CB_READ_HOLDING_REGISTERS] = readMemorySlave2;
		slaves[1].cbVector[CB_WRITE_HOLDING_REGISTERS] = writeMemorySlave2;
#endif
    // Set the serial port and slave to the given baudrate.
    SERIAL_PORT.begin(SERIAL_BAUDRATE);
    modbus.begin(SERIAL_BAUDRATE);
}
void loop()
{
    // Listen for modbus requests on the serial port.
    // When a request is received it's going to get validated.
    // And if there is a function registered to the received function code, this function will be executed.
	// leemos posicion encoder 
	memory_slave1[Paralelo::Map::POSITION] = Paralelo::ReadPositionEncoder();
	// leemos inclinometro
#if NUMBER_OF_SLAVES==2
		pos.UINT32= Serie::ReadEncoder();
		// leemos posicion encoder y en grados
		memory_slave2[Serie::Map::ENCODERL] = ((pos.Byte[2]<<8)|pos.Byte[3]);
		memory_slave2[Serie::Map::ENCODERH]= ((pos.Byte[0]<<8)|pos.Byte[1]);
#endif
	// procesamos modbus
    modbus.poll();
 	// verificamos cambios
	if (update1){
		ActualizaCambios(memory_slave1,Paralelo::Map::ADDR,&Paralelo::addr,1);
		ActualizaCambios(memory_slave1,Paralelo::Map::SPEED,&Paralelo::speed,2);
		ActualizaCambios(memory_slave1,Paralelo::Map::DIR,&Paralelo::dir,3);
		ActualizaCambios(memory_slave1,Paralelo::Map::GRAY,&Paralelo::gray,4);
		ActualizaCambios(memory_slave1,Paralelo::Map::BITS,&Paralelo::EncoderBits,6);
		update1=false;
	}
#if NUMBER_OF_SLAVES==2	
	if (update2 ){
		ActualizaCambios(memory_slave2,Serie::Map::ADDR,&Serie::addr,101);
		ActualizaCambios(memory_slave2,Serie::Map::SPEED,&Serie::speed,102);
		ActualizaCambios(memory_slave2,Serie::Map::FILTER,&Serie::filter,103);
		update2=false;
	}
#endif	
}
// Modbus handler functions
// The handler functions must return an uint8_t and take the following parameters:
//     uint8_t  fc - function code
//     uint16_t address - first register/coil address
//     uint16_t length/status - length of data / coil status
// Handle the function code Read Holding Registers (FC=03).
uint8_t readMemorySlave1(uint8_t fc, uint16_t address, uint16_t length)
{
    // Check if the requested addresses exist in the array.
    if (address > memory_slave1_size || (address + length) > memory_slave1_size)
    {
        return STATUS_ILLEGAL_DATA_ADDRESS;
    }
    // Write the memory array into the send buffer.
    for (uint8_t i = 0; i < length; ++i)
    {
        modbus.writeRegisterToBuffer(i, memory_slave1[address + i]);
    }
    return STATUS_OK;
}
// Handle the function codes Write Holding Register(s) (FC=06, FC=16)
uint8_t writeMemorySlave1(uint8_t fc, uint16_t address, uint16_t length)
{
    // Check if the requested addresses exist in the array
    if (address > memory_slave1_size || (address + length) > memory_slave1_size)
    {
        return STATUS_ILLEGAL_DATA_ADDRESS;
    }
    // Write the received data into the memory array.
    for (uint8_t i = 0; i < length; ++i)
    {
        memory_slave1[address + i] = modbus.readRegisterFromBuffer(i);
    }
	update1=true;
    return STATUS_OK;
}
#if NUMBER_OF_SLAVES==2	
// Handle the function code Read Holding Registers (FC=03).
uint8_t readMemorySlave2(uint8_t fc, uint16_t address, uint16_t length)
{
    // Check if the requested addresses exist in the array.
    if (address > memory_slave2_size || (address + length) > memory_slave2_size)
    {
        return STATUS_ILLEGAL_DATA_ADDRESS;
    }
    // Write the memory array into the send buffer.
    for (uint8_t i = 0; i < length; ++i)
    {
        modbus.writeRegisterToBuffer(i, memory_slave2[address + i]);
    }
    return STATUS_OK;
}
// Handle the function codes Write Holding Register(s) (FC=06, FC=16)
uint8_t writeMemorySlave2(uint8_t fc, uint16_t address, uint16_t length)
{
    // Check if the requested addresses exist in the array
    if (address > memory_slave2_size || (address + length) > memory_slave2_size)
    {
        return STATUS_ILLEGAL_DATA_ADDRESS;
    }
    // Write the received data into the memory array.
    for (uint8_t i = 0; i < length; ++i)
    {
        memory_slave2[address + i] = modbus.readRegisterFromBuffer(i);
    }
	update2=true;
    return STATUS_OK;
}
#endif