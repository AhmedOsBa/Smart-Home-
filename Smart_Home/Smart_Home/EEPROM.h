/*
 * EEPROM.h
 *
 * Created: 5/19/2021 7:01:45 AM
 *  Author: HP
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "I2C.h"

#define StringSize 4


void EEPROM_Init();


void EEPROM_Write_Data(uint8 data,uint8 loc);

uint8 EEPROM_Read_Data(uint8 loc);

void EEPROM_Write_Multiple_Data(uint8* data,uint8 size, uint8 loc);

uint8* EEPROM_Read_Multiple_Data(uint8 size, uint8 loc);


#endif /* EEPROM_H_ */