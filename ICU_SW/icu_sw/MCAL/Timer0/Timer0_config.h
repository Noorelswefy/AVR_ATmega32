/*
 * Timer_config.h
 *
 *  Created on: 18 Jun 2023
 *      Author: noor elswefy
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_
/*
 * Choose the mode of timer0
 * Normal
 * PWM OR Phase Correct
 * CTC
 * Fast PWM
 * */


#define TIMER0_MODE_SELECTION  FAST_PWM_MODE
/*
 * if the selection is Fast mode
 * Choose the functionality of Fast mode
 * 1-  Normal port operation, OC0 disconnected
 * 2- --------- Reserved---------
 * 3-  Clear OC0 on compare match, set OC0 at BOTTOM, (non-inverting mode)
 * 4-  Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)
 * */

#define FAST_PWM_Mode_SELECTION 	NON_INVERTING_MODE

#define TIMER0_CLOCK_SELECTION    	CLOCK_DIVIED_BY_8

#endif /* TIMER0_CONFIG_H_ */
