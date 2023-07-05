/*
 * Timer_private.h
 *
 *  Created on: 18 Jun 2023
 *      Author: noor elswefy
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define OCR0   *((volatile u8* ) 0x5C) //Timer/Counter0 Output Compare Register
#define TCCR0  *((volatile u8* ) 0x53)//Timer/Counter0 Overflow

// OCIE0 TOIE0
#define TIMSK  *((volatile u8* ) 0x59)
#define TIMSK_TOIE0 	0	//for overflow mode in Timer0
#define TIMSK_OCIE0 	1	//for compare mode in Timer0

#define TIFR   *((volatile u8* ) 0x58)

// FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00
#define TCCR0_FOC0		7
#define TCCR0_WGM00		6
#define TCCR0_COM01		5
#define TCCR0_COM00		4
#define TCCR0_WGM01		3
#define TCCR0_CS02 		2
#define TCCR0_CS01		1
#define TCCR0_CS00 		0




/*
#define TCCR1A  *((volatile u8* ) 0x4F)
//COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10
#define TCCR1A_COM1A1	7
#define TCCR1A_COM1A0	6
#define TCCR1A_COM1B1	5
#define TCCR1A_COM1B0	4
#define TCCR1A_FOC1A	3
#define TCCR1A_FOC1B 	2
#define TCCR1A_WGM11	1
#define TCCR1A_WGM10 	0

#define TCNT1H  *((volatile u8* ) 0x4E) //Timer/Counter1
#define TCNT1L  *((volatile u8* ) 0x4C)

#define TCCR1B  *((volatile u8* ) 0x4D)
// ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10
#define TCCR1B_WGM12	4
#define TCCR1B_WGM13	5
#define TCCR1B_CS10		0
#define TCCR1B_CS11		1
#define TCCR1B_CS12		2

#define OCR1AH *((volatile u8* ) 0x4B)
#define OCR1AL *((volatile u8* ) 0x4A)
*/

#define TIMER_u8_CLOCK_SELECTION_BIT_MASK  0b11111000

#define NO_CLOCK_SOURCE						0b000
#define NO_PRESCALLING						0b001
#define CLOCK_DIVIED_BY_8					0b010
#define CLOCK_DIVIED_BY_16					0b011
#define CLOCK_DIVIED_BY_32					0b100
#define CLOCK_DIVIED_BY_64					0b101
#define CLOCK_DIVIED_BY_256					0b110
#define CLOCK_DIVIED_BY_1024				0b111


#define NORMAL_MODE 						1
#define PWM_PHASE_CORRECT_MODE  			2
#define CTC_MODE 							3
#define FAST_PWM_MODE 						4


#define DISCONNECT							1
#define INVERTING_MODE						2
#define NON_INVERTING_MODE 					3
#endif /* TIMER0_PRIVATE_H_ */
