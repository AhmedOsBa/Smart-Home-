/*
 * LCD.c
 *
 * Created: 3/26/2021 1:12:21 PM
 *  Author: Ali
 */ 


#include   "LCD.h"



void LCD_Init(void)
{
	#if    LCD_MODE   ==    8
	
	DIO_SetPinDir(LCD_8BIT_MODE_CMD_PORT , LCD_RS_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_MODE_CMD_PORT , LCD_RW_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);
	
	DIO_SetPortDir(LCD_8BIT_MODE_DATA_PORT, DIO_PORT_OUTPUT);
	
	_delay_ms(100);
	
	LCD_WriteCommand(0X38);
	LCD_WriteCommand(0X0C);
	LCD_WriteCommand(0X01);
	LCD_WriteCommand(0X06);
    LCD_WriteCommand(0X02);
	
	
	
	
	#elif  LCD_MODE   ==    4
	
		DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT , LCD_RS_PIN , DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT , LCD_RW_PIN , DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);
		
		DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , LCD_D4, DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , LCD_D5, DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , LCD_D6, DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , LCD_D7, DIO_PIN_OUTPUT);
	
	   _delay_ms(100);
	   
	    LCD_WriteCommand(0X33);
	    LCD_WriteCommand(0X32);
		LCD_WriteCommand(0X28);
		LCD_WriteCommand(0X0C);
		LCD_WriteCommand(0X01);
		LCD_WriteCommand(0X06);
		LCD_WriteCommand(0X02);
	
	
	#endif
}

void LCD_WriteCommand(uint8 cmd)
{
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_RS_PIN , DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (cmd & 0xf0) | (PORTA & 0x0f);
	
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (cmd << 4) | (PORTA & 0x0f);
		
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(10);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_WriteChar(uint8 data)
{
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_RS_PIN , DIO_PIN_HIGH);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (data & 0xf0) | (PORTA & 0x0f);
	
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (data << 4) | (PORTA & 0x0f);
	
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(10);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_WriteString(uint8* str)
{
	uint8  cnt = 0;
	
	while(str[cnt] != '\0')
	{
		LCD_WriteChar(str[cnt]);
		cnt++;
	}
}

/*Your Assignment*/
void LCD_WriteInteger(sint32  num)
{
	
}
/****************/

void LCD_GoToLocation(uint8 row , uint8 col)
{
	uint8 Loc[2] = {0x80 , 0xc0};
	
	LCD_WriteCommand(Loc[row]+col);
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0X01);
}

