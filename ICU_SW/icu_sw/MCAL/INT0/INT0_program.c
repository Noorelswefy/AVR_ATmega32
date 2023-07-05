/*
 * INT0_program.c
 *
 *  Created on: 16 Jun 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "INT0_private.h"
#include "INT0_config.h"
#include "INT0_interface.h"



void volatile (*INT0_pvCallBackPtr) (void) = NULL;	//call back function pointer


void INT0_Init()
{

#if INT0_SENSE_MODE == INT0_FALLING_EDGE   // Trigger Falling Edge

	//Set sense control falling edge
	CLR_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);

#elif INT0_SENSE_MODE == INT0_ON_CHANGE_EDGE //Trigger On change
	SET_BIT(MCUCR, MCUCR_ISC00);
	CLR_BIT(MCUCR, MCUCR_ISC01);



#elif INT0_SENSE_MODE == INT0_RISING_EDGE  // Trigger Rising Edge
	SET_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);


#elif INT0_SENSE_MODE == INT0_LOW_LEVEL_EDGE // Trigger Low level

	CLR_BIT(MCUCR, MCUCR_ISC00);
	CLR_BIT(MCUCR, MCUCR_ISC01);

#endif


}

void INT0_Enable() {
	// Enable NTI0 PIE
	SET_BIT(GICR, GICR_INT0);

}
void INT0_Disable() {
	// Disable NTI0 PIE
	CLR_BIT(GICR, GICR_INT0);
}
void INT0_LatchMode(u8 copy_newMode) {


	switch(copy_newMode)
	{
	case 0:
		SET_BIT(MCUCR, MCUCR_ISC00);
		CLR_BIT(MCUCR, MCUCR_ISC01);
		break;
	case 1 :
		SET_BIT(MCUCR, MCUCR_ISC00);//INT0_RISING_EDGE
		SET_BIT(MCUCR, MCUCR_ISC01);
	}
}

void NTI0_SetCallBack(void (*fnAddress) (void))
{

	if(fnAddress != NULL)
	{
		INT0_pvCallBackPtr=fnAddress;
	}

}

void __vector_1(void)__attribute__((signal,used)); //attribute to avoid linker optmization
void __vector_1(void)
{
	INT0_pvCallBackPtr();
}

