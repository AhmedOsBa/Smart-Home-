/*
 * SPI.h
 *
 * Created: 4/30/2021 5:12:33 AM
 *  Author: HP
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"

void SPI_Master_Init(void);
void SPI_Slave_Init(void);

void SPI_Master_Init_Comm(void);

void SPI_Master_Term_Comm(void);	

uint8 SPI_Transfer_Recieve(uint8 data);





#endif /* SPI_H_ */