/*
 * INT0_private.h
 *
 *  Created on: 16 Jun 2023
 *      Author: noor elswefy
 */

#ifndef INT0_PRIVATE_H_
#define INT0_PRIVATE_H_

//#define EXTI_INT0 (*(volatile u8*) 0x02)

#define MCUCR	  (*(volatile u8*  )0X55)

#define GICR	  (*(volatile u8*  )0X5B)

#define GIFR	  (*(volatile u8*  )0X5A)

#endif /* INT0_PRIVATE_H_ */
