/*
 * Timer_prog.c
 *
 *  Created on: 18 Jun 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "Timer0_config.h"
#include "Timer0_interface.h"
#include "Timer0_private.h"





void (*y)(void) = NULL;	//call back function pointer

void TIMER0_voidInit(u8 Copy_u8ClockSelect){

#if TIMER0_MODE_SELECTION == NORMAL_MODE
CLR_BIT(TCCR0,TCCR0_WGM00);
CLR_BIT(TCCR0,TCCR0_WGM01);
#elif TIMER0_MODE_SELECTION == PWM_PHASE_CORRECT_MODE
SET_BIT(TCCR0,TCCR0_WGM00);
CLR_BIT(TCCR0,TCCR0_WGM01);
#elif TIMER0_MODE_SELECTION == CTC_MODE
CLR_BIT(TCCR0,TCCR0_WGM00);
SET_BIT(TCCR0,TCCR0_WGM01);
#elif TIMER0_MODE_SELECTION == FAST_PWM_MODE
SET_BIT(TCCR0,TCCR0_WGM00);
SET_BIT(TCCR0,TCCR0_WGM01);
/* Clear on compare */
CLR_BIT(TCCR0,TCCR0_COM00);
SET_BIT(TCCR0,TCCR0_COM01);
OCR0 = 64 ;		//Duty cycle 25%
#endif

//select clock // pre-scaler 8

SET_BIT(TCCR0,TCCR0_CS00);
CLR_BIT(TCCR0,TCCR0_CS01);
SET_BIT(TCCR0,TCCR0_CS02);


/*
TCCR0 &= TIMER_u8_CLOCK_SELECTION_BIT_MASK;
TCCR0 |= Copy_u8ClockSelect;*/


}
void TIMER0_voidEnable(){
	//Enable interrupt  for overflow in timer0 //
	SET_BIT(TIMSK,TIMSK_TOIE0);
}
void TIMER0_voidSetCallBack(void (*fnAddress) (void) )
{

	if(NULL != fnAddress)
	{

			y=fnAddress;
     }
}



void __vector_11()   __attribute__((signal)); //attribute to avoid linker optmization
void __vector_11()
{

		y();
}

