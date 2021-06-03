/*
 * Smart_Home.h
 *
 * Created: 5/27/2021 4:56:02 AM
 *  Author: HP
 */ 


#ifndef SMART_HOME_H_
#define SMART_HOME_H_

#include <string.h>

#include "STD.h"

#include "MCU.h"

#include "BIT_Math.h"

uint8 Check_Password(uint8* str,uint8* data);

void Send_Command(uint8 data);

uint8* Read_Password(void);





#endif /* SMART_HOME_H_ */