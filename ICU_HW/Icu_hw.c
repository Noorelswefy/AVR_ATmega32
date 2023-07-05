/*
 * Icu_hw.c
 *
 *  Created on: 26 Jun 2023
 *      Author: noor elswefy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "Timer1_interface.h"
#include "GIE_interface.h"

u16 PeriodTicks = 0; //T|period1
u16 OnTime = 0;

void ISR_ICU_HW();
int main() {
	DIO_voidSetPinDirection(PORTD_ID, PIN6, PIN_INPUT); //ICP pin
	DIO_voidSetPinValue(PORTD_ID, PIN6, PIN_LOW);

	/* LCD initialization */
	LCD_voidInit();
	Timer1_ICUInterruptEnable();
	Timer1_voidICUSetCallBack(ISR_ICU_HW);

	/* Timer1 initialization */
	Timer1_voidInit();

	/* Global interrupt Enable */
	GIE_voidEanble();

	while (1) {
		while((PeriodTicks == 0 && OnTime == 0 ));
				LCD_voidGoToXY(0,0);
				LCD_voidWriteString("T|on = ");
				LCD_voidWriteNumber(OnTime);
				LCD_voidGoToXY(1,0);
				LCD_voidWriteString("T|period1 = ");
				LCD_voidWriteNumber(PeriodTicks);
	}
}

void ISR_ICU_HW() {
	static u8 counter = 0;

	static u16 Tick1 = 0;
	static u16 Tick2 = 0;
	static u16 Tick3 = 0;
	if (counter == 1) {
		Tick1 = Timer1_u16GetInputCaptureReading();
	} else if (counter == 2) {
		Tick2 = Timer1_u16GetInputCaptureReading();

		PeriodTicks = Tick2 - Tick1;
		//falling edge
		Timer1_voidChangeSenseICUEdge(FALLING_EDGE);
	} else if (counter == 3) {
		Tick3 = Timer1_u16GetInputCaptureReading();
		OnTime = Tick3 - Tick2;
		Timer1_ICUInterruptDisable();


	}

}

