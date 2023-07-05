/*
 * Timer1_interface.h
 *
 *  Created on: 19 Jun 2023
 *      Author: noor elswefy
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_



void Timer1_voidInit(void);
void Timer1_voidClear();
u16  Timer1_u16GetInputCaptureReading();
void Timer1_voidSetCompChA(u16 Copy_u16Value);
void Timer1_voidICUSetCallBack(void (*pf)(void))

#endif /* TIMER1_INTERFACE_H_ */
