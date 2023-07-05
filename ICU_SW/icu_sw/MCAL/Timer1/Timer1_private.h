/*
 * Timer1_private.h
 *
 *  Created on: 19 Jun 2023
 *      Author: noor elswefy
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_




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


#define TCNT1L  *((volatile u8* ) 0x4C)
#define TCNT1H  *((volatile u8* ) 0x4D) //Timer/Counter1)
#define TCNT1  *((volatile u16* ) 0x4D)

#define TCCR1B  *((volatile u8* ) 0x4E)
// COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10
#define TCCR1B_WGM12	4
#define TCCR1B_WGM13	5
#define TCCR1B_CS10		0
#define TCCR1B_CS11		1
#define TCCR1B_CS12		2
#define TCCR1B_ICES1	6

#define OCR1AL *((volatile u8* ) 0x4A)
#define OCR1AH *((volatile u8* ) 0x4B)
#define OCR1A *((volatile u16* ) 0x4B)


#define ICR1   *((volatile u16* ) 0x46)


#endif /* TIMER1_PRIVATE_H_ */
