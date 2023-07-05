/*
 * UART_program.c
 *
 *  Created on: 2 Jul 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_config.h"
#include "UART_private.h"
#include "UART_interface.h"

#ifndef NULL
#define NULL		(void*)0
#endif


static u8   *UART_pu8Buffer_Arr = NULL;
static u8 	UART_u8TxSize;
static u8   UART_u8TxIndex=0;
u8 TX_u8State = TX_IDLE;
static void (*UART_pvNotificationFunc)(void) = NULL;   //call back function pointer

void UART_init() {
	/*1- receiver, transmitter enable
	 * 2- 8 bits
	 * 3- Asynchronous
	 * 4- no interrupts
	 * 5- normal speed
	 * 6- baud rate = 9600bps
	 * 7- no parity, 1 stop bit
	 * */

	u8 UCSRC_Value = 0;
	/* SET URSEL bit to use UCSRC register*/
	SET_BIT(UART_UCSRC, UCSRC_URSEL);
	/* Enable receiver, transmitter */
	SET_BIT(UART_UCSRB, UCSRB_RXEN);
	SET_BIT(UART_UCSRB, UCSRB_TXEN);

#if 	USART_MODE_SELECT ==	ASYNC
	CLR_BIT(UART_UCSRB, UCSRC_UMSEL);

#elif	USART_MODE_SELECT ==	SYNC
		SET_BIT(UART_UCSRB,UCSRC_UMSEL);
#endif

#if		DATA_SIZE_SELECT == 	_5_BIT
		CLR_BIT(UART_UCSRB ,UCSRB_UCSZ2);
		CLR_BIT(UCSRC_Value,UCSRC_UCSZ1);
		CLR_BIT(UCSRC_Value,UCSRC_UCSZ0);

#elif 	DATA_SIZE_SELECT == 	_6_BIT
		CLR_BIT(UART_UCSRB ,UCSRB_UCSZ2);
		CLR_BIT(UCSRC_Value,UCSRC_UCSZ1);
		SET_BIT(UCSRC_Value,UCSRC_UCSZ0);
#elif 	DATA_SIZE_SELECT == 	_7_BIT

		CLR_BIT(UART_UCSRB ,UCSRB_UCSZ2);
		SET_BIT(UCSRC_Value,UCSRC_UCSZ1);
		CLR_BIT(UCSRC_Value,UCSRC_UCSZ0);

#elif 	DATA_SIZE_SELECT == 	_8_BIT
	CLR_BIT(UART_UCSRB, UCSRB_UCSZ2);
	SET_BIT(UCSRC_Value, UCSRC_UCSZ1);
	SET_BIT(UCSRC_Value, UCSRC_UCSZ0);
#elif 	DATA_SIZE_SELECT == 	_9_BIT
	SET_BIT(UART_UCSRB ,UCSRB_UCSZ2);
	SET_BIT(UCSRC_Value,UCSRC_UCSZ1);
	SET_BIT(UCSRC_Value,UCSRC_UCSZ0);
#endif

#if 	BAUD_RATE_16_MHZ_SELECT ==  BAUD_RATE_9600
		UART_UBRRL = 51;
#endif
	/*Assign the variable into the register*/
	UART_UCSRC = UCSRC_Value;
}
void UART_SendCharacter(u8 Copy_u8SendChar) {

	/* Wait until the transmit buffer is Empty  */
	while (GET_BIT(UART_UCSRA,UCSRA_UDRE) == 0);

	/* (UDR) is ready to receive new data*/
	/* Send new data*/
	UART_UDR = Copy_u8SendChar;
}
void UART_SendString(const u8 *Copy_u8SendChar) {
	u8 Local_u8Counter = 0;
		if (Copy_u8SendChar != NULL) {
			while (Copy_u8SendChar[Local_u8Counter] != '\0') {
				UART_SendCharacter(Copy_u8SendChar[Local_u8Counter]);
				Local_u8Counter++;
			}
		}else
		{
			/*report Error*/
		}

}
u8 UART_ReceiveCharacter() {
	/* Wait until Receive flag is raised */
	while (GET_BIT(UART_UCSRA,UCSRA_RXC) == 0);


	/*Receive the data*/
	return UART_UDR;
}
u8 UART_SendBufferAsync( u8 * Buffer , u8 size,void (*Notification)(void))
{
	u8 Local_u8ErrorState = OK;

	for( u8 i = 0 ; i <= size ; i++)
	{
		UART_pu8Buffer_Arr [i]= Buffer[i];

	}
	UART_pvNotificationFunc = Notification;
    /*set the first Element in buffer*/
    UART_UDR = Buffer[UART_u8TxIndex];
    /* Enable USART transmit interrupt*/
    SET_BIT(UART_UCSRB,UCSRB_UDRIE);


    return Local_u8ErrorState;

}
void __vector_15(void)__attribute__((signal,used)); //attribute to avoid linker optimization
void __vector_15(void)
{
	TX_u8State = TX_BUSY;
	/* Increnemt index*/
	UART_u8TxIndex ++;

	if( UART_u8TxIndex != UART_u8TxSize)
	{
		/* Transimminting is not complete*/
		if(TX_u8State == TX_IDLE)
		{
			/*start transmission */
		 UART_UDR = UART_pu8Buffer_Arr[UART_u8TxIndex];

		}
	}else{ /* Transimminting is complete*/
		TX_u8State = TX_BUSY;
		UART_pvNotificationFunc();
	    CLR_BIT(UART_UCSRB,UCSRB_UDRIE);

	}
}
/*
u8 UART_ReceiveString() {
	u8 Local_u8Counter=0;
	u8 *str;
	str[Local_u8Counter]=UART_ReceiveCharacter();

	while (str[Local_u8Counter] != '\0')
		{

			Local_u8Counter++;
		}


	return UART_UDR;
}
*/
