/* Software ICU
 * Use Timer0 to generate PWM
 * Use External interrupt INT0 to trigger rising and falling edges
 * Print the period time and ON time  on LCD */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "INT0_interface.h"
#include "Timer0_interface.h"
#include "Timer1_interface.h"
#include "GIE_interface.h"
#include "LCD_Interface.h"


// T|period = T|ticks * num of ticks

u16 PeriodTicks = 0; //T|period1
u16 OnTime = 0;


void ISR_ICU();

int main() {

	//External interrupt pin INT0
	DIO_voidSetPinDirection(PORTD_ID, PIN2, PIN_INPUT);
	DIO_voidSetPinValue(PORTD_ID, PIN2, PIN_LOW);
	//OC0--> PWM
	DIO_voidSetPinDirection(PORTB_ID, PIN3, PIN_OUTPUT);
	DIO_voidSetPinValue(PORTB_ID, PIN3, PIN_LOW);

	/* LCD initialization */
	LCD_voidInit();

	/* Timer0 initialization */
	TIMER0_voidInit();  //PWM ---- pre-scaler 8

	/* Timer1 initialization */
	Timer1_voidInit();	//Normal mode --- pre-scaler 8
	/* Get ready the callback function before interrupt getting triggered*/
	NTI0_SetCallBack(ISR_ICU);
	INT0_Init();    //Rising edge


	/* Global interrupt Enable */
	GIE_voidEanble();

	while (1) {

		/* wait until PWM parameters got read*/
		while((PeriodTicks == 0 && OnTime == 0 ));
		LCD_voidGoToXY(0,0);
		LCD_voidWriteString("T|on = ");
		LCD_voidWriteNumber(OnTime);
		LCD_voidGoToXY(1,0);
		LCD_voidWriteString("T|period1 = ");
		LCD_voidWriteNumber(PeriodTicks);

	}
}
void ISR_ICU(){
	static u8 counter =0;
	counter++;

	if(counter == 1)
	{
		Timer1_voidClear();
	}else if(counter == 2)
	{
		PeriodTicks = Timer1_u16GetTimerReading();
		INT0_LatchMode(1);
	}else if(counter == 3)
	{
		OnTime = Timer1_u16GetTimerReading();
		OnTime -= PeriodTicks;
		INT0_Disable();
	}

}
