/*
 * UART_interface.h
 *
 *  Created on: 2 Jul 2023
 *      Author: noor elswefy
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


#define BUFFER_SIZE 128
/*typedef struct{
	u8* txBuffer[BUFFER_SIZE];
	u8  txIndex =0 ;
	u8  txLength = 0;   //No. of conversions in the chain
	void (*Notification)(void);
}Buffer_type;
*/

void UART_init();
void UART_SendCharacter(u8 Copy_u8SendChar);
void UART_SendString(const u8 *Copy_u8SendChar);
u8 UART_ReceiveCharacter();
u8 UART_SendBufferAsync( u8 * Buffer , u8 size,void (*Notification)(void));
#endif /* UART_INTERFACE_H_ */
