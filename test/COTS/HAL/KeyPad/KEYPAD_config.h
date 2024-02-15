//
// Created by sohai on 9/17/2023.
//

#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H



#define KEYPAD_PORT  DIO_PORTC

#define KEYPAD_R0 DIO_PIN0
#define KEYPAD_R1 DIO_PIN1
#define KEYPAD_R2 DIO_PIN2
#define KEYPAD_R3 DIO_PIN3

#define KEYPAD_C0 DIO_PIN4
#define KEYPAD_C1 DIO_PIN5
#define KEYPAD_C2 DIO_PIN6
#define KEYPAD_C3 DIO_PIN7

#define KEYPAD_ROWS_INIT DIO_PIN0
#define KEYPAD_ROWS_END DIO_PIN3

#define KEYPAD_COLS_INIT DIO_PIN4
#define KEYPAD_COLS_END DIO_PIN7

#define KEYPAD_NOT_PRESSED_VALUE 255
#define KEYPAD_SWITCH_ON 0
#define KEYPAD_SWITCH_OFF 1

#endif //KEYPAD_CONFIG_H
