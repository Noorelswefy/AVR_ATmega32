/*
 * SPI_program.c
 *
 *  Created on: 3 Jul 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"
void SPI_voidInitMaster()
{
	SET_BIT(SPI_SPCR,SPCR_SPR0);
	SET_BIT(SPI_SPCR,SPCR_MSTR);
	SET_BIT(SPI_SPCR,SPCR_SPE);
}
void SPI_voidInitSlave()
{
	CLR_BIT(SPI_SPCR,SPCR_MSTR);
	SET_BIT(SPI_SPCR,SPCR_SPE);

}
u8 SPI_u8Transceive(u8 Copy_u8Data)
{
	SPI_SPDR = Copy_u8Data;
	while( GET_BIT(SPI_SPSR,SPSR_SPIF) == 0);
	return SPI_SPDR;
}
