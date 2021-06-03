/*
 * Smart_Home_2.c
 *
 * Created: 6/3/2021 12:15:53 PM
 * Author : HP
 */ 

#define F_CPU 16000000

#include <util/delay.h>

#include "SPI.h"

#include "DC_Motor.h"

int main(void)
{
	DC_Motor_Init();
	
	uint8 received = 0;
	
	// set pin1 of portc output for led
	
	DIO_SetPin_Dir(DIO_PORTC,DIO_PIN1, DIO_PIN_OUTPUT);
	
	// init the motor pins 

	
	
	
	
	
	//init spi of mcu2 as slave 
	SPI_Slave_Init();
	
	_delay_ms(1000);
	while (1)
	{
		// receive data from mcu1 and transmit value which means that transmission is complete
		received=SPI_Transfer_Recieve(3);
		//check for the value sent by user 1 to toggle led and 2 to open door 
		if(received=='1')
		{
			DIO_TogglePin(DIO_PORTC,DIO_PIN1);
			
			received=0;
		}
		 if (received=='2')
		{
				
			// set speed of motor
			DC_Motor_Set_Speed(100);
			//open door by motor 
			DC_Motor_Set_Dir(ANTI_CLOCK_WISE_DIR);	
			DC_Motor_Start();
			//wait period of time then auto close the door 
			_delay_ms(1000);
			DC_Motor_Set_Dir(CLOCK_WISE_DIR);
			_delay_ms(1000);
			//stop dc motor after closing door 
			DC_Motor_Stop();	
			received=0;
		}
		
	}
	_delay_ms(1000);
}