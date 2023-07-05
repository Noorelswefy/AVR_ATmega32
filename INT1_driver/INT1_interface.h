/*
 * INT1_interface.h
 *
 *  Created on: 16 Jun 2023
 *      Author: noor elswefy
 */

#ifndef INT1_INTERFACE_H_
#define INT1_INTERFACE_H_


#define INT1_FALLING_EDGE			0
#define INT1_RISING_EDGE			1
#define INT1_ON_CHANGE_EDGE			2
#define INT1_LOW_LEVEL_EDGE			3


#define MCUCR_ISC11		3
#define MCUCR_ISC10		2

#define GICR_INT1		7

#define GIFR_INT1		7


void INT1_Init(u8 copy_u8mode);
void INT1_Enable();
void INT1_Disable();
void INT1_LatchMode(u8 copy_newMode);
void INT1_SetCallBack(void (*fnAddress) (void));



#endif /* INT1_INTERFACE_H_ */
