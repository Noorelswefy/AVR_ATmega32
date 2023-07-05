/*
 * SPI_interface.h
 *
 *  Created on: 3 Jul 2023
 *      Author: noor elswefy
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidInitMaster();
void SPI_voidInitSlave();
u8 SPI_u8Transceive(u8 Copy_u8Data);
#endif /* SPI_INTERFACE_H_ */
