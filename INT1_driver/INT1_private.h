/*
 * INT1_private.h
 *
 *  Created on: 16 Jun 2023
 *      Author: noor elswefy
 */

#ifndef INT1_PRIVATE_H_
#define INT1_PRIVATE_H_



#define MCUCR	  (*(volatile u8*  )0X55)

#define GICR	  (*(volatile u8*  )0X5B)

#define GIFR	  (*(volatile u8*  )0X5A)

#endif /* INT1_PRIVATE_H_ */
