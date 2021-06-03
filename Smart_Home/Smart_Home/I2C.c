/*
 * I2C.c
 *
 * Created: 5/19/2021 4:58:09 AM
 *  Author: HP
 */ 

#include "I2C.h"


void I2C_Master_Init(void)
{
	/* Clk 400 khz */
	TWBR=0x07;
	
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
	
	/* Enable I2C*/
	
	SET_BIT(TWCR,2);
	
}

void I2C_Slave_Init(void)
{
	/* Slave Address*/
	TWAR = (0x01<<1);
	
	/* Enable I2C*/
	
	SET_BIT(TWCR,2);
	
	
}

void I2C_Start_Condition(void)
{
	TWCR = 0xA4; // bit 2 to renable the i2c , bit 7 to to clear flag, bit 5 to get start condition
	
	//blocking on the flag
	while(GET_BIT(TWCR,7) == 0);
	
	//blocking on operation
	while( (TWSR & 0xf8) != START_ACK );
	
}

void I2C_Start_Repeated_Start(void)
{
	TWCR = 0xA4; // bit 2 to renable the i2c , bit 7 to to clear flag, bit 5 to get start condition
	
	//blocking on the flag
	while(GET_BIT(TWCR,7)==0);
	
	//blocking on operation
	while( (TWSR & 0xf8) != REP_START_ACK );
	
}

void I2C_Send_SlaveAddress_Write(uint8 addr)
{
	//Slave address write 
	TWDR= (addr<<1);
	//clear flag enable I2C
	TWCR=0x84;
	
	//blocking on the flag
	while(GET_BIT(TWCR,7)==0);
	
	//blocking on operation
	while( (TWSR & 0xf8) != SLAVE_ADD_AND_WR_ACK);
}

void I2C_Send_SlaveAddress_Read(uint8 addr)
{
	//Slave address read
	TWDR = (addr <<1) | 0x01;
	
	//clear flag enable I2C 
	TWCR=0x84;
	
	//blocking on the flag
	while(GET_BIT(TWCR,7)==0);
	
	//blocking on operation
	while( (TWSR & 0xf8) != SLAVE_ADD_AND_RD_ACK);
}

void I2C_Send_DataByte(uint8 Data)
{	
	TWDR=Data;
	
	//clear flag enable I2C
	TWCR=0x84;
	
	//blocking on the flag
	while(GET_BIT(TWCR,7)==0);
	
	//blocking on operation
	while( (TWSR & 0xf8) != WR_BYTE_ACK);
	
}

uint8 I2C_Read_DataByte(void)
{
	//clear flag enable I2C
	TWCR=0x84;
	
	//blocking on the flag
	while(GET_BIT(TWCR,7)==0);
	
	//blocking on operation
	while( (TWSR & 0xf8) != RD_BYTE_WITH_ACK);
	
	return TWDR;
}

void I2C_Stop_Condition(void)
{
	TWCR = 0x94;
	
	
	
}
