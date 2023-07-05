/*
 * INT0_interface.h
 *
 *  Created on: 16 Jun 2023
 *      Author: noor elswefy
 */

#ifndef INT0_INTERFACE_H_
#define INT0_INTERFACE_H_



#define INT0_FALLING_EDGE			0
#define INT0_RISING_EDGE			1
#define INT0_ON_CHANGE_EDGE			2
#define INT0_LOW_LEVEL_EDGE			3



#define MCUCR_ISC01		1
#define MCUCR_ISC00		0

#define GICR_INT0		6

#define GIFR_INT0		6

void INT0_Init();
void INT0_Enable();
void INT0_Disable();
void INT0_LatchMode(u8 copy_newMode);
void NTI0_SetCallBack(void (*fnAddress) (void));

#endif /* INT0_INTERFACE_H_ */
