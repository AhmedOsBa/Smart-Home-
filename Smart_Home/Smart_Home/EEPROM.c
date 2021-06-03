/*
 * EEPROM.c
 *
 * Created: 5/19/2021 7:01:31 AM
 *  Author: HP
 */ 

#include "EEPROM.h"
#define F_CPU 16000000

#include <util/delay.h>


void EEPROM_Init()
{
	I2C_Master_Init();
}

void EEPROM_Write_Data(uint8 data,uint8 loc)
{
	I2C_Start_Condition();
	
	I2C_Send_SlaveAddress_Write(0b01010000);
	
	I2C_Send_DataByte(loc);
	
	I2C_Send_DataByte(data);
	
	I2C_Stop_Condition();
	
	
}



void EEPROM_Write_Multiple_Data(uint8* data,uint8 size, uint8 loc)
{
		uint8 i =0;
		I2C_Start_Condition();
		
		I2C_Send_SlaveAddress_Write(0b01010000);
		
		I2C_Send_DataByte(loc);
		
		while(i<size)
		{
			I2C_Send_DataByte(data[i]);
			
			i++;
		}
		
		I2C_Stop_Condition();
}

uint8 EEPROM_Read_Data(uint8 loc)
{
	uint8 data ;
	I2C_Start_Condition();
	
	I2C_Send_SlaveAddress_Write(0b01010000);
	
	I2C_Send_DataByte(loc);
	
	I2C_Start_Repeated_Start();
	
	I2C_Send_SlaveAddress_Read(0b01010000);
	
	data = I2C_Read_DataByte();
	
	I2C_Stop_Condition();
	
	return data ;
}


//create function which read multiple data from eeprom to check for password

uint8* EEPROM_Read_Multiple_Data(uint8 size, uint8 loc)
{
	uint8 data[StringSize];
	uint8 i =0;
	
	while(data[i] !=  '\0')
	{
		data[i]=EEPROM_Read_Data(loc+i);
		
		i++;
	}
	
	
	uint8* dataa=data;
	
	return dataa;
	
	
}