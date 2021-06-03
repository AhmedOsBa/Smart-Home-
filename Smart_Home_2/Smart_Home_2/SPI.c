/*
 * SPI.c
 *
 * Created: 4/30/2021 5:12:21 AM
 *  Author: HP
 */ 

#include "SPI.h"

void SPI_Master_Init(void)
{
	/* Miso*/
	DIO_SetPin_Dir(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);
	/* MIso*/
	DIO_SetPin_Dir(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	/* SCK CLK */
	DIO_SetPin_Dir(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);
	/*SS*/
	DIO_SetPin_Dir(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);
	
	/* 0b 01010011*/
	SPI->SPCR |=0x53;
	
	/*  ss off */
	DIO_SetPin_Value(DIO_PORTB, DIO_PIN4, DIO_PIN_LOW);
	
}
void SPI_Slave_Init(void)
{
	/* Miso*/
	DIO_SetPin_Dir(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	/* MIso*/
	DIO_SetPin_Dir(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);
	/* SCK CLK */
	DIO_SetPin_Dir(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);
	/*SS*/
	DIO_SetPin_Dir(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);
	/* 0b 01000000 */
	SPI->SPCR |=0x40;
	
}

void SPI_Master_Init_Comm(void)
{
	DIO_SetPin_Value(DIO_PORTB, DIO_PIN4, DIO_PIN_LOW);
	
}

void SPI_Master_Term_Comm(void)
{
	DIO_SetPin_Value(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);
}

uint8 SPI_Transfer_Recieve(uint8 data)
{
	uint8 rec_data=0;
	
	SPI->SPDR=data;
	
	while (GET_BIT(SPI->SPSR , 7)==0);
	
	rec_data = SPI-> SPDR ;
	
	return rec_data;
	
}
