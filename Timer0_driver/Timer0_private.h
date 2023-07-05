/*
 * Timer_private.h
 *
 *  Created on: 18 Jun 2023
 *      Author: noor elswefy
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define OCR0   *((volatile u8* ) 0x5C) //Timer/Counter0 Output Compare Register
#define TCCR0  *((volatile u8* ) 0x53)

// OCIE0 TOIE0
#define TIMSK  *((volatile u8* ) 0x59)
#define TIMSK_TOIE0 	0	//for overflow mode in Timer0
#define TIMSK_OCIE0 	1	//for compare mode in Timer0

#define TIFR   *((volatile u8* ) 0x58)

// FOC0 WGM00 COM01 	COM00 WGM01 CS02 CS01 CS00
#define TCCR0_FOC0		7
#define TCCR0_WGM00		6
#define TCCR0_COM01		5
#define TCCR0_COM00		4
#define TCCR0_WGM01		3
#define TCCR0_CS02 		2
#define TCCR0_CS01		1
#define TCCR0_CS00 		0

#define TIMER_u8_CLOCK_SELECTION_BIT_MASK  0b11111000
#define NO_CLOCK_SOURCE			000
#define NO_PRESCALLING			001
#define CLOCK_DIVIED_BY_8		010
#define CLOCK_DIVIED_BY_16		3
#define CLOCK_DIVIED_BY_32		100
#define CLOCK_DIVIED_BY_64		101
#define CLOCK_DIVIED_BY_256		110
#define CLOCK_DIVIED_BY_1024	111


#define NORMAL_MODE 			1
#define PWM_PHASE_CORRECT_MODE  2
#define CTC_MODE 				3
#define FAST_PWM_MODE 			4

#endif /* TIMER0_PRIVATE_H_ */
