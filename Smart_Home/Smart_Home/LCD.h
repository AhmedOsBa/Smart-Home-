/*
 * LCD.h
 *
 * Created: 3/26/2021 1:12:44 PM
 *  Author: Ali
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_CFG.h"
#define   F_CPU     16000000
#include <util/delay.h>


void LCD_Init(void);

void LCD_WriteCommand(uint8 cmd);

void LCD_WriteChar(uint8 data);

void LCD_WriteString(uint8* str);

/*Your Assignment*/
void LCD_WriteInteger(sint32  num);
/****************/

void LCD_GoToLocation(uint8 row , uint8 col);

void LCD_Clear(void);



#endif /* LCD_H_ */