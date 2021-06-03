/*
 * UART.h
 *
 * Created: 4/28/2021 5:39:38 AM
 *  Author: HP
 */ 


#ifndef UART_H_
#define UART_H_

#include "STD.h"

#include "BIT_Math.h"

#include "MCU.h"

void UART_Init(void);

void UART_Tx(uint8 data);

void UART_String_Tx(uint8* str);

uint8 UART_Rx(void);




#endif /* UART_H_ */