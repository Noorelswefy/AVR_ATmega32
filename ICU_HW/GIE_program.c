/*
 * GIE_program.c
 *
 *  Created on: 15 Jun 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "GIE_private.h"



void GIE_voidEanble()
{
	//GIFR INTF1 INTF0 INTF2
	SET_BIT(SREG,I_BIT);
}
void GIE_voidDisable()
{
	CLR_BIT(SREG,I_BIT);
}
