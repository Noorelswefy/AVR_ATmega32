/*
 * SendData.c
 *
 *  Created on: 2 Jul 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "UART_interface.h"


int main()
{
u8 data;
	UART_init();

	UART_SendCharacter('A');
	while(1)
	{
//data = UART_ReceiveCharacter();
//UART_SendCharacter(data);
	}
}
