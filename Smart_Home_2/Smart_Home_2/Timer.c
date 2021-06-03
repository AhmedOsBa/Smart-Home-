/*
 * Timer.c
 *
 * Created: 4/11/2021 3:07:54 AM
 *  Author: HP
 */ 

#include "Timer.h"
#include <avr/interrupt.h>


uint32 NUM_OVF=0;

uint32 INIT_VALUE=0;
void (*Ptr_0)(void);
void (*Ptr_1)(void);



void Timer0_Init(void)

{
	/* Set Normal MOde8*/
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	
	
}

void Timer0_Set_Delay(uint32 Delay_MS)
{
	uint8 Tick_Time=(1024/16);
	
	uint32 Total_Ticks=((Delay_MS*1000)/Tick_Time);
	
	NUM_OVF=Total_Ticks/256;
	
	INIT_VALUE=256-(Total_Ticks % 256);
	
	
	
	if(INIT_VALUE !=0 )

	{
	NUM_OVF++;
	}
	
}

void Timer0_Start(void)
{
	
	/* start timer using prescaler 1024 8*/
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	
	/* Enabel GLOBAL_INT*/
	
	SET_BIT(SREG,7);
	
	/*Enable OverFlow_INT*/
	SET_BIT(TIMSK,0);
	
}

void Timer0_Stop(void)
{
	/* Remove Timer*/
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	
}

void Set_Call_Back(void (*p)(void))
{
	Ptr_0=p;
}

ISR(TIMER0_OVF_vect)
{
	static uint32 cnt=0;
	
	cnt++;
	
	if(cnt == NUM_OVF)
	{
		(*Ptr_0)();
		TCNT0=INIT_VALUE;
		
	}
}
/***************************************************************** TIMER1***********************/


void Timer1_Init(void)
{
	/* select mode ctc */
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	
	/* Enabel GLOBAL_INT*/
	
	SET_BIT(SREG,7);
	
	/*Enable CTC_INT*/
	SET_BIT(TIMSK,4);
	
	
	
}

void Timer1_Set_Delay(uint32 Delay_MS)
{
	if(Delay_MS<4000)
	{
		uint8 Tick_Time=1024/16;
		uint32 NUM_Ticks=(Delay_MS * 1000)/Tick_Time;
		OCR1A=NUM_Ticks-1;
	}
}

void Timer1_Start(void)
{
	SET_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
	
}

void Timer1_Stop(void)
{
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
	
}

void Set_Call_Back1(void (*p)(void))
{
	Ptr_1=p;
}

ISR(TIMER1_COMPA_vect)
{
	(*Ptr_1)();
}

void PWM0_Init(void)
{
	/* OC0_PIN_OUTPUT*/
	SET_BIT(DDRB,3);
	/* FAST_PWM*/
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	/* NON INVERTED MODE*/
	 SET_BIT(TCCR0,5);
}

void PWM0_Adjust(uint16 Duty_Cycle)
{
	OCR0=((Duty_Cycle * 256)/100)-1;
}

void PWM0_Start(void)
{
	/* no prescaler */
	SET_BIT(TCCR0,0);
}