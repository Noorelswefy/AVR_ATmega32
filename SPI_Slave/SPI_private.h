/*
 * SPI_private.h
 *
 *  Created on: 3 Jul 2023
 *      Author: noor elswefy
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define  SPI_SPDR	*((volatile u8 * ) 0x2F) /*  SPI Data Register */
#define  SPI_SPSR	*((volatile u8 * ) 0x2E)
//SPIF WCOL – – – – – SPI2X
#define  SPSR_SPIF		7
#define  SPSR_WCOL		6
#define  SPSR_SPI2X		0

#define  SPI_SPCR	*((volatile u8 * ) 0x2D)
//SPIE SPE DORD MSTR CPOL CPHA SPR1 SPR0
#define	 SPCR_SPIE		7
#define	 SPCR_SPE		6
#define	 SPCR_DORD		5
#define	 SPCR_MSTR		4
#define	 SPCR_CPOL		3
#define	 SPCR_CPHA		2
#define	 SPCR_SPR1		1
#define	 SPCR_SPR0		0


#define CLOCK_PHASE_SETUP			0
#define CLOCK_PHASE_SAMPLE			1

#define CLOCK_POLARITY_LOW			0
#define CLOCK_POLARITY_HIGH			1

//#define CLOCK_POLARITY_LOW
#define DIV_BY_8
#define DIV_BY_16
#define DIV_BY_32
#define DIV_BY_64
#define DIV_BY_128
#define DIV_BY_2



#endif /* SPI_PRIVATE_H_ */
