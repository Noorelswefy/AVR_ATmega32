/*
 * Timer1_program.c
 *
 *  Created on: 19 Jun 2023
 *      Author: noor elswefy
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer1_config.h"
#include "Timer1_private.h"
#include "Timer1_interface.h"

void (*ICU_pvCallBackPtr)(void)=NULL;

void Timer1_voidInit(void)
{
	/*ICU initially on rising edge*/
	SET_BIT(TCCR1B,TCCR1B_ICES1);



	/*normal mode*/
	/*prescaler : division by 8*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
}
void Timer1_ICUInterruptEnable()
{
	/*ICU interrupt enable*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
}
void Timer1_ICUInterruptDisable()
{
	/*ICU interrupt enable*/
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

void Timer1_voidClear()
{
	TCNT1 =0;
}
void Timer1_voidSetCompChA(u16 Copy_u16Value)
{
	OCR1A=Copy_u16Value;
}
u16 Timer1_u16GetInputCaptureReading(void)
{

	return ICR1;
}
u16  Timer1_u16GetTimerReading()
{
	return TCNT1;
}
void Timer1_voidChangeSenseICUEdge( u8 Copy_u8SenseMode)

{
	if( Copy_u8SenseMode == RISING_EDGE)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}else if(Copy_u8SenseMode == FALLING_EDGE) {
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
}

void Timer1_voidICUSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	if(Copy_pvCallBackFunc!=NULL)
	{
		ICU_pvCallBackPtr=Copy_pvCallBackFunc;
	}
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(ICU_pvCallBackPtr!=NULL)
	{
		ICU_pvCallBackPtr();
	}
}

