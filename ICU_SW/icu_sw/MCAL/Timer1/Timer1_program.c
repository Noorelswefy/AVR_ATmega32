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
	//Normal mode
	/*Set prescaler to divide by 8*/

		CLR_BIT(TCCR1B,TCCR1B_CS10);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS12);



	/*Mode 14 in waveform generation mode*/
	//Fast PWM
  /*CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	//Set on top Clear on compare
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		CLR_BIT(TCCR1A,TCCR1A_COM1A0);
		*/




	/*Set ICR1 to required top value of 20000 for servo*/
//	ICR1=20000;

	/* Initial Value for Timer1 */
		TCNT1 = 0;


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
/*
void Timer1_voidChangeSenseMode(u8 Copy_u8Edge)
{
	if(ICU_RISING_EDGE==Copy_u8Edge)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(ICU_FALLING_EDGE==Copy_u8Edge)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
}*/
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

