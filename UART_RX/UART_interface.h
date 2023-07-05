/*
 * UART_interface.h
 *
 *  Created on: 2 Jul 2023
 *      Author: noor elswefy
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_init();
void UART_SendCharacter(u8 Copy_u8SendChar);
void UART_SendString(const u8 *Copy_u8SendChar);
u8 UART_ReceiveCharacter();

#endif /* UART_INTERFACE_H_ */
