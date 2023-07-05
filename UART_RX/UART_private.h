/*
 * UART_private.h
 *
 *  Created on: 2 Jul 2023
 *      Author: noor elswefy
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

//USART Data Register
#define UART_UDR		*((volatile u8 *)0x2C)
#define UART_UCSRA		*((volatile u8 *)0x2B)
//RXC TXC UDRE FE DOR PE U2X MPCM
#define UCSRA_RXC		7
#define UCSRA_TXC		6
#define UCSRA_UDRE		5
#define UCSRA_FE		4
#define UCSRA_DOR		3
#define UCSRA_PE		2
#define UCSRA_U2X		1
#define UCSRA_MPCM		0

#define UART_UCSRB		*((volatile u8*)0x2A)
//RXCIE TXCIE UDRIE RXEN TXEN UCSZ2 RXB8 TXB8
#define UCSRB_RXCIE     7
#define UCSRB_TXCIE     6
#define UCSRB_UDRIE     5
#define UCSRB_RXEN      4
#define UCSRB_TXEN      3
#define UCSRB_UCSZ2     2
#define UCSRB_RXB8      1
#define UCSRB_TXB8      0

//same address of the UBRRH Register
#define UART_UCSRC		*((volatile u8*)0x40)

#define UCSRC_URSEL		7				/*Register Select*/
#define UCSRC_UMSEL		6				/*USART Mode Select (Synchronous or Asynchronous)*/
#define UCSRC_UPM1		5				/*USART Parity Mode Bit 1*/
#define UCSRC_UPM0		4				/*USART Parity Mode Bit 0*/
#define UCSRC_USBS		3				/*Stop Bit Select*/
#define UCSRC_UCSZ1		2				/*USART Character Size BIT 1*/
#define UCSRC_UCSZ0		1				/*USART Character Size BIT 0*/
#define UCSRC_UCPOL		0				/*USART Clock Polarity*/

//URSEL UMSEL UPM1 UPM0 USBS UCSZ1 UCSZ0 UCPOL
#define UART_UBRRH		*((volatile u8 *)0x40)
//URSEL – – – UBRR[11:8]
#define UBRRH_URSEL			7					/*Register Select*/

#define UART_UBRRL		*((volatile u8 *)0x29)


#define PARITY_MODE_DISABLE		0
#define PARITY_MODE_EVEN		2
#define PARITY_MODE_ODD			3

#define BAUD_RATE_9600			51

#define STOP_1_BIT				0
#define STOP_2_BITS				1

#define _5_BIT			0
#define _6_BIT			1
#define _7_BIT			2
#define _8_BIT			3
#define _9_BIT			7

#define ASYNC			0
#define SYNC			1
#endif /* UART_PRIVATE_H_ */
