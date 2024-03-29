//
// Created by sohai on 9/13/2023.
//

#ifndef LCD_PROGRAM_C_LCD_CONFIG_H
#define LCD_PROGRAM_C_LCD_CONFIG_H


#define LCD_DATA_PORT   DIO_u8PORTC
#define LCD_CTR_PORT   DIO_u8PORTB

#define LCD_RS_PIN   DIO_u8PIN0
#define LCD_RW_PIN   DIO_u8PIN1
#define LCD_E_PIN    DIO_u8PIN2


/* Defining some commands */

// Function Set
#define FUNC_SET_SMALL_ONE_LINE 0b00110000
#define FUNC_SET_BIG_ONE_LINE 0b00110100
#define FUNC_SET_SMALL_TWO_LINE 0b00111000
#define FUNC_SET_BIG_TWO_LINE 0b00111100

// DISPLAY ON/OFF
#define DISPLAY_ON_NO_CURSOR 0b00001100
#define DISPLAY_ON_CURSOR 0b00001110
#define DISPLAY_ON_BLINK 0b00001101
#define DISPLAY_OFF 0b00001000

//DISPLAY CLEAR
#define DISPLAY_CLEAR 1

//ENTRY MODE SET
#define MODE_SET_INC_SHIFTING 7
#define MODE_SET_INC_NO_SHIFTING 6
#define MODE_SET_DEC_SHIFTING 5
#define MODE_SET_DEC_NO_SHIFTING 4

// CURSOR AND DISPLAY SHIFTING
#define SHIFT_CURSOR_LEFT 0b00010000
#define SHIFT_CURSOR_RIGHT 0b00010100
#define SHIFT_DISPLAY_LEFT 0b00011000
#define SHIFT_DISPLAY_RIGHT 0b00011100

//RETURN HOME
#define RETURN_HOME 2

#define LCD_WRITE_FROM_LEFT 0
#define LCD_WRITE_FROM_RIGHT 1

#endif //LCD_PROGRAM_C_LCD_CONFIG_H
