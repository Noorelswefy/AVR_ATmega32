/*
 * Switch_program.c
 *
 *  Created on: 16 Jun 2023
 *      Author: noor elswefy
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "Switch_interface.h"

void SWITCH_voidInit(SW_Type SW_Config){
	DIO_voidSetPinDirection(SW_Config.port, SW_Config.pin, PIN_INPUT);

	if(SW_Config.pull_state == SW_Int_PULLUP)
	{
		DIO_voidSetPinValue(SW_Config.port, SW_Config.pin, LOGIC_HIGH);

	}
}
u8 SWITCH_u8GetPressed(SW_Type SW_Config){

	u8 Local_u8SWval  = DIO_voidGetBitValue(SW_Config.port,SW_Config.port);
	u8 Local_u8PressedSW;
	if(LOGIC_LOW == Local_u8SWval){

		//busy waiting
		while(LOGIC_LOW == Local_u8SWval){
			Local_u8PressedSW = DIO_voidGetBitValue(SW_Config.port,SW_Config.port);


		}
		return Local_u8PressedSW;
	}

}
