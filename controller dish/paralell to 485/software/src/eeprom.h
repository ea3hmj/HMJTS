/*
	EEprom.h
*/
#ifndef EEprom_h
#define EEprom_h

#include "Arduino.h"
#include <math.h>
#include <EEPROM.h>
typedef union
{
  float Float;
  byte Byte[4];
} myFloat;

typedef union
{
  uint32 UINT32;
  byte Byte[4];
} myUint32;


class EEprom
{
public:
					EEprom(void);
	float			readFLOAT(int );
	void			writeFLOAT(int ,float );
	int				readINT(int );
	void			writeINT(int ,int );
	byte 			readBYTE(int pos);
	void 			writeBYTE(int pos,byte f);
protected:
	
private:
	
};

#endif
