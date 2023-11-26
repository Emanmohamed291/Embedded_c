/*
 * DIO.c
 *
 * Created: 11/25/2023 6:46:29 PM
 *  Author: Eman
 */ 
#include "DIO.h"
/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig){
	DIO_enumError_t Ret_enumErrorState = DIO_enumNullPointer;/* initialstate is not OK */
	/* validation */
	if(Copy_enumPortNum > DIO_enumPortD){
		Ret_enumErrorState = DIO_enumWrongPort;
	}
	else if(Copy_enumConfig > DIO_enumInputExternalPD){
		Ret_enumErrorState = DIO_enumWrongConfig;
	}
	/* CODE */
	else{
		Ret_enumErrorState = DIO_enumOk;
		/* choose the port */
		switch (Copy_enumPortNum){
			case DIO_enumPortA:/*portA*/
				switch(Copy_enumConfig){/*switch for config*/
					case DIO_enumOutput:/*PORTA output*/
						DDRA = 0xFF;
						break;
					case DIO_enumInputInternalPU:/*PORTA input_ipu*/
						DDRA = 0x00;
						PORTA = 0xFF;
						break;
					case DIO_enumInputExternalPD:/*PORTA input_epd*/
						DDRA = 0x00;
						PORTA = 0x00;
						break;
					default:
						break;					
				}
				break;
			case DIO_enumPortB:/*portB*/
				switch(Copy_enumConfig){/*switch for config*/
					case DIO_enumOutput:/*PORTB output*/
						DDRB = 0xFF;
						break;
					case DIO_enumInputInternalPU:/*PORTB input_ipu*/
						DDRB = 0x00;
						PORTB = 0xFF;
						break;
					case DIO_enumInputExternalPD:/*PORTB input_epd*/
						DDRB = 0x00;
						PORTB = 0x00;
						break;
					default:
						break;
					}
				break;
			case DIO_enumPortC:/*portC*/
				switch(Copy_enumConfig){/*switch for config*/
					case DIO_enumOutput:/*PORTC output*/
						DDRC = 0xFF;
						break;
					case DIO_enumInputInternalPU:/*PORTC input_ipu*/
						DDRC = 0x00;
						PORTC = 0xFF;
						break;
					case DIO_enumInputExternalPD:/*PORTC input_epd*/
						DDRC = 0x00;
						PORTC = 0x00;
						break;
					default:
						break;
				}
				break;									
			default:
				break;
		}
		
	}
	return Ret_enumErrorState;
}
/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum, DIO_enumLogicState_t Copy_enumLogicState){
	DIO_enumError_t Ret_enumErrorState = DIO_enumNullPointer;/* initialstate is not OK */
	/* validation */
	if(Copy_enumPortNum > DIO_enumPortD){		
		Ret_enumErrorState = DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum > DIO_enumPin7){
		Ret_enumErrorState = DIO_enumWrongPin;
	}
	else if(Copy_enumLogicState > DIO_enumLogicHigh){
		Ret_enumErrorState = DIO_enumWrongConfig;
	}
	/*	CODE	*/
	else{
		Ret_enumErrorState = DIO_enumOk;
		switch(Copy_enumPortNum){
			case DIO_enumPortA:
				switch(Copy_enumLogicState){
					case DIO_enumLogicHigh:
						SET_BIT(PORTA, Copy_enumPinNum);
						break;
					case DIO_enumLogicLow:
						CLR_BIT(PORTA, Copy_enumPinNum);
						break;
					default:
						break;
				}
				break;
			case DIO_enumPortB:
				switch(Copy_enumLogicState){
					case DIO_enumLogicHigh:
					SET_BIT(PORTB, Copy_enumPinNum);
					break;
					case DIO_enumLogicLow:
					CLR_BIT(PORTB, Copy_enumPinNum);
					break;
					default:
					break;
				}
				break;
			case DIO_enumPortC:
				switch(Copy_enumLogicState){
					case DIO_enumLogicHigh:
					SET_BIT(PORTC, Copy_enumPinNum);
					break;
					case DIO_enumLogicLow:
					CLR_BIT(PORTC, Copy_enumPinNum);
					break;
					default:
					break;
				}
				break;
			default:
				break;
	}		
		}
	
	return Ret_enumErrorState;
}

/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig){
	DIO_enumError_t Ret_enumErrorState = DIO_enumNullPointer;/* initialstate is not OK */
	/* validation */
	if(Copy_enumPortNum > DIO_enumPortD){
		Ret_enumErrorState = DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum > DIO_enumPin7){
		Ret_enumErrorState = DIO_enumWrongPin;
	}
	else if(Copy_enumConfig > DIO_enumInputExternalPD){
		Ret_enumErrorState = DIO_enumWrongConfig;
	}
	/* CODE */
	else{
		Ret_enumErrorState = DIO_enumOk;
		/* choose the port */
		switch (Copy_enumPortNum){
			case DIO_enumPortA:/*portA*/
			switch(Copy_enumConfig){/*switch for config*/
				case DIO_enumOutput:/*PORTA output*/
				SET_BIT(DDRA, Copy_enumPinNum) ;
				break;
				case DIO_enumInputInternalPU:/*PORTA input_ipu*/
				CLR_BIT(DDRA, Copy_enumPinNum);
				SET_BIT(PORTA, Copy_enumPinNum);
				break;
				case DIO_enumInputExternalPD:/*PORTA input_epd*/
				CLR_BIT(DDRA, Copy_enumPinNum);
				CLR_BIT(PORTA, Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;
			case DIO_enumPortB:/*portB*/
			switch(Copy_enumConfig){/*switch for config*/
				case DIO_enumOutput:/*PORTB output*/
				SET_BIT(DDRB, Copy_enumPinNum) ;
				break;
				case DIO_enumInputInternalPU:/*PORTB input_ipu*/
				CLR_BIT(DDRB, Copy_enumPinNum);
				SET_BIT(PORTB, Copy_enumPinNum);
				break;
				case DIO_enumInputExternalPD:/*PORTB input_epd*/
				CLR_BIT(DDRB, Copy_enumPinNum);
				CLR_BIT(PORTB, Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;
			case DIO_enumPortC:/*portC*/
			switch(Copy_enumConfig){/*switch for config*/
				case DIO_enumOutput:/*PORTC output*/
				SET_BIT(DDRC, Copy_enumPinNum) ;
				break;
				case DIO_enumInputInternalPU:/*PORTC input_ipu*/
				CLR_BIT(DDRC, Copy_enumPinNum);
				SET_BIT(PORTC, Copy_enumPinNum);
				break;
				case DIO_enumInputExternalPD:/*PORTC input_epd*/
				CLR_BIT(DDRC, Copy_enumPinNum);
				CLR_BIT(PORTC, Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;
				default:
				break;
		}
		
	}

	return Ret_enumErrorState;	
}
/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState){
	DIO_enumError_t Ret_enumErrorState = DIO_enumNullPointer;/* initialstate is not OK */
	/* validation */
	if(Copy_enumPortNum > DIO_enumPortD){
		Ret_enumErrorState = DIO_enumWrongPort;
	}
	else if(Copy_enumLogicState > DIO_enumLogicHigh){
		Ret_enumErrorState = DIO_enumWrongConfig;
	}
	/*	CODE	*/
	else{
		Ret_enumErrorState = DIO_enumOk;
		switch(Copy_enumPortNum){
			case DIO_enumPortA:
			switch(Copy_enumLogicState){
				case DIO_enumLogicHigh:
				PORTA = 0xFF;
				break;
				case DIO_enumLogicLow:
				PORTA = 0x00;
				break;
				default:
				break;
			}
			break;
			case DIO_enumPortB:
			switch(Copy_enumLogicState){
				case DIO_enumLogicHigh:
				PORTB = 0xFF;
				break;
				case DIO_enumLogicLow:
				PORTB = 0x00;
				break;
				default:
				break;
			}
			break;
			case DIO_enumPortC:
			switch(Copy_enumLogicState){
				case DIO_enumLogicHigh:
				PORTC = 0xFF;
				break;
				case DIO_enumLogicLow:
				PORTC = 0x00;
				break;
				default:
				break;
			}
			break;
			default:
			break;
		}
	}
		
	return Ret_enumErrorState;
}
/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue){
	DIO_enumError_t Ret_enumErrorState = DIO_enumNullPointer;/* initialstate is not OK */
	/* validation */
	if(Copy_enumPortNum > DIO_enumPortD){
		Ret_enumErrorState = DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum > DIO_enumPin7){
		Ret_enumErrorState = DIO_enumWrongPin;
	}
	/* CODE */
	else{
		Ret_enumErrorState = DIO_enumOk;
		switch(Copy_enumPortNum){
			case DIO_enumPortA:
		        *Add_Pu8PinValue = GET_BIT(PINA, Copy_enumPinNum);
				break;
			case DIO_enumPortB:
				*Add_Pu8PinValue = GET_BIT(PINB, Copy_enumPinNum);
				break;
			case DIO_enumPortC:
				*Add_Pu8PinValue = GET_BIT(PINB, Copy_enumPinNum);
				break;
			default:
				break;
		}
	}
	return Ret_enumErrorState;
}