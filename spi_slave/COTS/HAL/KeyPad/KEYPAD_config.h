//
// Created by sohai on 9/17/2023.
//

#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H



#define KEYPAD_PORT  DIO_u8PORTC

#define KEYPAD_R0 DIO_u8PIN0
#define KEYPAD_R1 DIO_u8PIN1
#define KEYPAD_R2 DIO_u8PIN2
#define KEYPAD_R3 DIO_u8PIN3

#define KEYPAD_C0 DIO_u8PIN4
#define KEYPAD_C1 DIO_u8PIN5
#define KEYPAD_C2 DIO_u8PIN6
#define KEYPAD_C3 DIO_u8PIN7

#define KEYPAD_ROWS_INIT DIO_u8PIN0
#define KEYPAD_ROWS_END DIO_u8PIN3

#define KEYPAD_COLS_INIT DIO_u8PIN4
#define KEYPAD_COLS_END DIO_u8PIN7

#define KEYPAD_NOT_PRESSED_VALUE 255
#define KEYPAD_SWITCH_ON 0
#define KEYPAD_SWITCH_OFF 1

#endif //KEYPAD_CONFIG_H
