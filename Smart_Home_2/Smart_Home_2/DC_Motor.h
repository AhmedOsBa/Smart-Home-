/*
 * DC_Motor.h
 *
 * Created: 4/20/2021 12:12:35 AM
 *  Author: HP
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "Timer.h"
#include "DIO.h"

typedef enum
{
	
	CLOCK_WISE_DIR,
	ANTI_CLOCK_WISE_DIR,
	}DC_Motor_Dir;
	
	
void DC_Motor_Init(void);

void DC_Motor_Set_Dir(DC_Motor_Dir dir);

void DC_Motor_Set_Speed(uint8 speed);

void DC_Motor_Start(void);

void DC_Motor_Stop(void);








#endif /* DC_MOTOR_H_ */