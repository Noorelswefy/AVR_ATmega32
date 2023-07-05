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

/* Slave program*/

int main() {

	u8 ReceivedData;
	DIO_voidSetPinDirection(PORTB_ID, PIN6, PIN_OUTPUT); //miso
	DIO_voidSetPinDirection(PORTB_ID, PIN5, PIN_INPUT);//mosi

	DIO_voidSetPinValue(PORTB_ID, PIN4, PIN_HIGH);//ss

	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_OUTPUT);//led

	SPI_voidInitSlave();

	while (1)
	{
		ReceivedData = SPI_u8Transceive(10); //10 is a garbage

		if(ReceivedData == 1)
		{
			DIO_voidSetPinValue(PORTA_ID, PIN0, PIN_HIGH);
		}
	}
}
