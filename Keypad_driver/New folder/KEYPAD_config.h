/******************************************************************/
/******************************************************************/
/*********		Author: Amgad Samir			***********************/
/*********		Component: KEYPAD			***********************/
/*********		Layer: HAL					***********************/
/*********		Version: 1.00				***********************/
/******************************************************************/
/******************************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define NO_KEY_PRESSED_VALUE	0xFF

#define KEYPAD_u8_COL_PORT		PORTD
#define KEYPAD_u8_ROW_PORT		PORTC


#define KEYPAD_u8_ROW0			PIN5
#define KEYPAD_u8_ROW1			PIN4
#define KEYPAD_u8_ROW2			PIN3
#define KEYPAD_u8_ROW3			PIN2

#define KEYPAD_u8_COLUMN0		PIN7
#define KEYPAD_u8_COLUMN1		PIN6
#define KEYPAD_u8_COLUMN2		PIN5
#define KEYPAD_u8_COLUMN3		PIN3

#define KEYPAD_KEYS_ARR4x4		{ {1,2,3,4} , {5,6,7,8}, {9,10,11,12}, {13,14,15,16} }


#endif
