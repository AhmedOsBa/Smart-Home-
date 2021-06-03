/*
 * Smart_Home.c
 *
 * Created: 5/27/2021 4:55:42 AM
 *  Author: HP
 */ 

#include "Smart_Home.h"

#include "EEPROM.h"

#include "LCD.h"

#include "UART.h"

#include "SPI.h"
#define F_CPU 16000000

#include <util/delay.h>



uint8* Read_Password(void)
{
	  
	  uint8 uartdata =0;
	  //uisng keyword static to avoid variable being thrown after frame of method leave stack 
	 static uint8 arrsize[4];
	  
	  uint8 i=0;
	  //make sure password is only 4 char 
	  while(i<4)
		  {
			  //read data sent from the bluetooth 
			 uartdata=UART_Rx();
			 //when data arrive 
			  if(uartdata)
			  {
				  
				  //put current data in the ith elemnt in static array 
					  arrsize[i]=uartdata;
					 
					 //increment 
					  i++;
				  
		  }
		  }
		  // to make sure all methods will deal with this variable as string end string with null character represent end of string
		  arrsize[4]='\0';
		  
		  //pointer to string which can be used by check password and eeprom
		  uint8* dataa=arrsize;
		  return dataa;
}
//function will return 1 for correct match and 0 for mismatch
uint8 Check_Password(uint8 * str,uint8* data)
{

	// compare two pointers to data to make sure both strings are identical 
	
	//strcmp return 0 for identical match return 1 for mismatch
	if(strcmp(str,data)==0)
	{
		
		LCD_WriteString("Welcome");
		
	
		return 1;
	}
	
	else
	{
		LCD_WriteString("Wrong Password");
		return 0;
	}
}


// transfer data to mcu2 using spi communication protocol
void Send_Command(uint8 data)
{
	 
	 uint8 rxdata=0;
	  
	 rxdata = SPI_Transfer_Recieve(data);
	 
	 if(rxdata==2)
	 {
		 LCD_Clear();
		 LCD_WriteString("Sent Successfully");
		 _delay_ms(500);
	 }
	
	
}


//show diffrent commands user can send to mcu2 using lcd

void Options(void)
{
	
	LCD_Clear();
	LCD_WriteString("Toggle Lights: ");
	LCD_WriteChar('1');
	
	_delay_ms(500);
	
	LCD_Clear();
	LCD_WriteString("Open Door:  ");
	LCD_WriteChar('2');
	
	_delay_ms(500);
	
	LCD_Clear();
	LCD_WriteString("New Pass:  ");
	LCD_WriteChar('3');
	_delay_ms(500);
}