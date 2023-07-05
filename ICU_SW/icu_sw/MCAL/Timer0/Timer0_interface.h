/*
 * Timer_interface.h
 *
 *  Created on: 18 Jun 2023
 *      Author: noor elswefy
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#define TCNT0  (*(volatile u8* ) 0x52)
#define OCR0   *((volatile u8* ) 0x5C)


void TIMER0_voidInit();
void TIMER0_voidEnable();
void TIMER0_voidDisable();
void TIMER0_voidSetCallBack(void (*fnAddress) (void) );



#endif /* TIMER0_INTERFACE_H_ */
