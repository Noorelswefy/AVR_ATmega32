/*
 * ReceiveData.c
 *
 *  Created on: 2 Jul 2023
 *      Author: noor elswefy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "UART_interface.h"


int main()
{

	UART_init();
	LCD_voidInit();

	u8 Received_data;
	while(1)
	{
	Received_data =  UART_RecieveCharacter();

	LCD_voidWriteData(Received_data);
	}
}
