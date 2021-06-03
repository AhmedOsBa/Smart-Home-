/*
 * Smart_Home.c
 *
 * Created: 5/25/2021 4:59:08 AM
 * Author : HP
 */ 

#include "UART.h"

#include "LCD.h"

#include  "SPI.h"



#include "EEPROM.h"
#include "LCD.h"
#include "Smart_Home.h"
#define F_CPU 16000000

#include <util/delay.h>


int main(void)
{
	
	//init communication i2c for eeprom uart for bluetooth spi for mcu2
	UART_Init();
	EEPROM_Init();
	LCD_Init();
	
	SPI_Master_Init();
	SPI_Master_Init_Comm();
	
	_delay_ms(1000);
	
	uint8 pass_check=0;
	uint8 rxdata=0;
	uint8* pass=0;
	
	

	
	//set default password which is 1234 user can change it using command 
	
	EEPROM_Write_Multiple_Data("1234",4,0x00);
	
	 while (1)
	 {
		 //pass check variable make sure user entered correct password
		 if(pass_check==1)
		 {
			 //show options
			 Options();
			 LCD_Clear();
			 LCD_WriteString("Send Command");
			 //recieve commandfrom bluetooth
			 uint8 data =UART_Rx();
			 
			 
			  Send_Command(data);
			 
			 //only command which is dealt with inside mcu1 is the password reset 
			 if(data=='3')
			 {
				 LCD_Clear();
				 LCD_WriteString("New Password");
				 //read password from user 
				 pass=Read_Password();
				 // save new password to the eeprom 
				 EEPROM_Write_Multiple_Data(pass,4,0x00);
			 }
			 
			 // every time the user want to send command to system user must send password
			pass_check=0;
			
		 }
		
		else
		//password checking part 
		{
			LCD_Clear();
			LCD_WriteString("Enter Password");
			
			//user asked to enter password
				
			 pass=Read_Password();
			
			// correct password is recalled from the eeprom 
			uint8* data=EEPROM_Read_Multiple_Data(4,0x00);
			
			_delay_ms(500);
			
			LCD_Clear();
			
			//use pass check method and override the passcheck variable to make system accepts user command 
			pass_check = Check_Password(data,pass);
			_delay_ms(500);
			
			LCD_Clear();
			
		}
		
}
_delay_ms(1000);
}

