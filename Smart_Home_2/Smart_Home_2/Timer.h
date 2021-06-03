/*
 * Timer.h
 *
 * Created: 4/11/2021 3:09:14 AM
 *  Author: HP
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "Bit_Math.h"

#include "MCU.h"

/***************************************************************** TIMER0***********************/
void Timer0_Init(void);

void Timer0_Set_Delay(uint32 Delay_MS);

void Timer0_Start(void);

void Timer0_Stop(void);

void Set_Call_Back0(void (*p)(void));

/***************************************************************** TIMER1***********************/


void Timer1_Init(void);

void Timer1_Set_Delay(uint32 Delay_MS);

void Timer1_Start(void);

void Timer1_Stop(void);

void Set_Call_Back1(void (*p)(void));

/************************************************************* PWM0******************************************/

void PWM0_Init(void);

void PWM0_Adjust(uint16 Duty_Cycle);

void PWM0_Start(void);




#endif /* TIMER_H_ */