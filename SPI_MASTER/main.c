/*
 * main.c
 *
 *  Created on: 3 Jul 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "SPI_interface.h"
#include <util/delay.h>
/* Master program */

int main()
{
	//(MISO) PB6 -- I/P for master
	//(MOSI) PB5 -- O/P for master
	//(SCK)  PB7 -- O/P for master
	//(SS)   PB4 -- I/P Pull up or O/P for Master&Slave

	DIO_voidSetPinDirection(PORTB_ID, PIN6, PIN_INPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN5, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN7, PIN_OUTPUT);
	DIO_voidSetPinValue(PORTB_ID, PIN4, PIN_HIGH);

	SPI_voidInitMaster();
	while(1)
	{
		SPI_u8Transceive(1);

		_delay_ms(1000);

	}
}
