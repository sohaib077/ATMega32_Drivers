/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: sohai
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KeyPad/KEYPAD_config.h"
#include "../HAL/KeyPad/KEYPAD_interface.h"
#include "avr/delay.h"

void main() {
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
	while (1) {
		DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_HIGH);
		_delay_ms(2000);
		DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_HIGH);
		_delay_ms(2000);
		}
}

