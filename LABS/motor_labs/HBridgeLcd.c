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
#define STABLE 0
#define RIGHT 1
#define LEFT 2
void main() {
	LCD_voidInit();
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN2, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN2, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_HIGH);
	u8 Local_u8Switch1value, Local_u8Switch2value;
	u8 Local_u8MotorState ;
	while (1) {
		DIO_u8GetPinValue(DIO_u8PORTB, DIO_u8PIN0, &Local_u8Switch1value);
		DIO_u8GetPinValue(DIO_u8PORTB, DIO_u8PIN1, &Local_u8Switch2value);
		if (Local_u8Switch1value == 0 && Local_u8Switch2value != 0) {
			DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN2, DIO_u8PIN_HIGH);
			if (Local_u8MotorState != LEFT) {
				Local_u8MotorState = LEFT;
				LCD_voidSendCommand(DISPLAY_CLEAR);
				LCD_voidSendString("LEFT");
			}
		} else if (Local_u8Switch1value != 0 && Local_u8Switch2value == 0) {
			DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN2, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_HIGH);
			if (Local_u8MotorState != RIGHT) {
				Local_u8MotorState = RIGHT;
				LCD_voidSendCommand(DISPLAY_CLEAR);
				LCD_voidSendString("RIGHT");
			}
		} else {
			DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN2, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_LOW);
			if (Local_u8MotorState != STABLE) {
				Local_u8MotorState = STABLE;
				LCD_voidSendCommand(DISPLAY_CLEAR);
				LCD_voidSendString("STABLE");
			}
		}
	}
}

