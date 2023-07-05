/*
 * WDT_private.h
 *
 *  Created on: 1 Jul 2023
 *      Author: noor elswefy
 */

#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_


#define WDTCR *((volatile u8 *) 0x41)
//– – – WDTOE WDE WDP2 WDP1 WDP0
#define WDTCR_WDTOE 	4
#define WDTCR_WDE 		3
#define WDTCR_WDP2 		2
#define WDTCR_WDP1		1
#define WDTCR_WDP0		0



#define TIMEOUT_16_K 	0	//For Vcc = 5.0 ->Time-out = 16.3ms
#define TIMEOUT_32_K 	1	//For Vcc = 5.0 ->Time-out = 32.5ms
#define TIMEOUT_64_K 	2	//For Vcc = 5.0 ->Time-out = 65ms
#define TIMEOUT_128_K 	3	//For Vcc = 5.0 ->Time-out = 0.13s
#define TIMEOUT_256_K 	4	//For Vcc = 5.0 ->Time-out = 0.26s
#define TIMEOUT_512_K 	5	//For Vcc = 5.0 ->Time-out = 0.52s
#define TIMEOUT_1024_K 	6	//For Vcc = 5.0 ->Time-out = 1.0s
#define TIMEOUT_2048_K 	7	//For Vcc = 5.0 ->Time-out = 2.1s
#endif /* WDT_PRIVATE_H_ */
