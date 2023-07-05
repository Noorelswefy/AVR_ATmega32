/*
 * Timer_prog.c
 *
 *  Created on: 18 Jun 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
//#include "DIO_Interface.h"
#include "Timer0_config.h"
#include "Timer0_interface.h"
#include "Timer0_private.h"





void (*TIMER0_pvCallBackFunc)(void) = NULL;	//call back function pointer

void TIMER0_voidInit(){



	/*Fast PWM*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Clear on compare, set on top*/
	SET_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);

	/*Compare match value for duty cycle = 25%*/
	OCR0=64;

	/*Pre-scaler : division by 8*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

/*
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
#endif

// Fast PWM mode
#if FAST_PWM_Mode_SELECTION == DISCONNECT
CLR_BIT(TCCR0,TCCR0_COM00);
CLR_BIT(TCCR0,TCCR0_COM01);
#elif FAST_PWM_Mode_SELECTION == INVERTING_MODE
SET_BIT(TCCR0,TCCR0_COM00);
SET_BIT(TCCR0,TCCR0_COM01);
#elif FAST_PWM_Mode_SELECTION == NON_INVERTING_MODE
CLR_BIT(TCCR0,TCCR0_COM00);
SET_BIT(TCCR0,TCCR0_COM01);
#endif


//Prescaler : division by 8
CLR_BIT(TCCR0,TCCR0_CS00);
SET_BIT(TCCR0,TCCR0_CS01);
CLR_BIT(TCCR0,TCCR0_CS02);

//Compare match value for duty cycle = 25%
OCR0=64;
*/
/*
TCCR0 &= TIMER0_CLOCK_SELECTION;
TCCR0 |= Copy_u8ClockSelect;

*/


}

/*

void TIMER0_voidEnable(){


#if TIMER0_MODE_SELECTION == NORMAL_MODE
	//Enable interrupt  for overflow in timer0 //
	SET_BIT(TIMSK,TIMSK_TOIE0);
#elif TIMER0_MODE_SELECTION == PWM_PHASE_CORRECT_MODE

#elif TIMER0_MODE_SELECTION == CTC_MODE
//Enable interrupt  for ctc in timer0 //
SET_BIT(TIMSK,TIMSK_OCIE0);

#elif TIMER0_MODE_SELECTION == FAST_PWM_MODE




#endif

}
*/
void TIMER0_voidDisable()
{
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
}
void TIMER0_voidSetCallBack(void (*fnAddress) (void) )
{

	if(NULL != fnAddress)
	{

		TIMER0_pvCallBackFunc=fnAddress;
     }
}



void __vector_11()   __attribute__((signal)); //attribute to avoid linker optmization
void __vector_11()
{

	TIMER0_pvCallBackFunc();
}

