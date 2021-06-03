/*
 * DC_Motor.c
 *
 * Created: 4/20/2021 12:12:19 AM
 *  Author: HP
 */ 

#include "DC_Motor.h"

void DC_Motor_Init(void)
{
	DIO_SetPin_Dir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
	
	DIO_SetPin_Dir(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT);
		
	PWM0_Init();
}

void DC_Motor_Set_Dir(DC_Motor_Dir dir)
{
	switch (dir)
	{
		case CLOCK_WISE_DIR:
		DIO_SetPin_Value(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
		
		DIO_SetPin_Value(DIO_PORTC,DIO_PIN4	,DIO_PIN_LOW);
		
		break;
		
		case ANTI_CLOCK_WISE_DIR:
		
		DIO_SetPin_Value(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		
		DIO_SetPin_Value(DIO_PORTC,DIO_PIN4	,DIO_PIN_HIGH);
		
		break;
		
		default:
		break;
	}
}

void DC_Motor_Set_Speed(uint8 speed)
{
	PWM0_Adjust(speed);
}

void DC_Motor_Start(void)
{
	PWM0_Start();
	
}

void DC_Motor_Stop(void)
{
			DIO_SetPin_Value(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
			
			DIO_SetPin_Value(DIO_PORTC,DIO_PIN4	,DIO_PIN_LOW);
			
}
