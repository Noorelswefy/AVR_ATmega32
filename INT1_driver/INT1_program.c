/*
 * INT1_program.c
 *
 *  Created on: 16 Jun 2023
 *      Author: noor elswefy
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "INT1_private.h"
#include "INT1_config.h"
#include "INT1_interface.h"



void (*x) (void);


void INT1_Init(u8 copy_u8mode)
{

#if INT1_SENSE_MODE == INT1_FALLING_EDGE   // Trigger Falling Edge

	//Set sense control falling edge
	CLR_BIT(MCUCR, MCUCR_ISC10);
	SET_BIT(MCUCR, MCUCR_ISC11);

#elif INT1_SENSE_MODE == INT1_ON_CHANGE_EDGE //Trigger On change
	SET_BIT(MCUCR, MCUCR_ISC00);
	CLR_BIT(MCUCR, MCUCR_ISC11);



#elif INT1_SENSE_MODE == INT1_RISING_EDGE  // Trigger Rising Edge
	SET_BIT(MCUCR, MCUCR_ISC10);
	SET_BIT(MCUCR, MCUCR_ISC11);


#elif INT1_SENSE_MODE == INT1_LOW_LEVEL_EDGE // Trigger Low level

	CLR_BIT(MCUCR, MCUCR_ISC10);
	CLR_BIT(MCUCR, MCUCR_ISC11);

#endif
	CLR_BIT(GICR, GICR_INT1);
	SET_BIT(GIFR, GIFR_INT1);

}

void INT1_Enable() {
	// Enable NTI0 PIE
	SET_BIT(GICR, GICR_INT1);

}
void INT1_Disable() {
	// Disable NTI0 PIE
	CLR_BIT(GICR, GICR_INT1);
}
void INT1_LatchMode(u8 copy_newMode) {

	if (copy_newMode == INT1_FALLING_EDGE) {
		SET_BIT(MCUCR, MCUCR_ISC10);
		CLR_BIT(MCUCR, MCUCR_ISC11);

	} else if (copy_newMode == INT1_RISING_EDGE) {
		SET_BIT(MCUCR, MCUCR_ISC10);
		SET_BIT(MCUCR, MCUCR_ISC11);
	} else if (copy_newMode == INT1_LOW_LEVEL_EDGE) {
		CLR_BIT(MCUCR, MCUCR_ISC10);
		CLR_BIT(MCUCR, MCUCR_ISC11);
	} else {
		SET_BIT(MCUCR, MCUCR_ISC10);
		SET_BIT(MCUCR, MCUCR_ISC11);
	}
}

void INT1_SetCallBack(void (*fnAddress) (void))
{

	if(fnAddress != NULL)
	{
	x=fnAddress;
	}

}

void __vector__2(void)__attribute__((signal,used)); //attribute to avoid linker optmization
void __vector__2(void)
{
		x();
}

