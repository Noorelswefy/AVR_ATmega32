/*
 * Switch_interface.h
 *
 *  Created on: 16 Jun 2023
 *      Author: noor elswefy
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

/**
 SW_Int_PULLUP
 SW_Ext_PULLUP
 SW_Ext_PULLDOWN
 SW_IFLAOTING
 */
#define SW_Int_PULLUP	0
#define SW_Ext_PULLUP	1
#define SW_Ext_PULLDOWN	2
#define SW_FLOATING	3

typedef struct {
	u8 port;
	u8 pin;
	u8 pull_state;
}SW_Type;


void SWITCH_voidInit(SW_Type SW_Config);
u8 SWITCH_u8GetPressed(SW_Type SW_Config);




#endif /* SWITCH_INTERFACE_H_ */
