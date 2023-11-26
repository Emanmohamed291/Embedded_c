/*
 * Task_2.c
 *
 * Created: 11/26/2023 10:52:34 PM
 *  Author: Eman
 */ 
#define  F_CPU 1000000
#include "../MCAL/DIO.h"
#include "util/delay.h"

int main(void)
{
	/* Replace with your application code */
	DIO_enumLogicState_t Current_State;
	u8 counter =0;
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin0, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin1, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin2, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin3, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin4, DIO_enumInputInternalPU);
	while (1)
	{	
		DIO_enumReadState(DIO_enumPortA, DIO_enumPin4, &Current_State);
		if(Current_State == DIO_enumLogicLow){
			_delay_ms(300);
			if(Current_State == DIO_enumLogicLow){
				counter++;
			}
		}
		counter = counter%16;
		DIO_enumSetPin(DIO_enumPortA, DIO_enumPin0, GET_BIT(counter,0));
		DIO_enumSetPin(DIO_enumPortA, DIO_enumPin1, GET_BIT(counter,1));
		DIO_enumSetPin(DIO_enumPortA, DIO_enumPin2, GET_BIT(counter,2));
		DIO_enumSetPin(DIO_enumPortA, DIO_enumPin3, GET_BIT(counter,3));
	}
}
