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

void main() {
  DIO_u8SetPinDirection(DIO_u8PORTB ,DIO_u8PIN0 , DIO_u8PIN_OUTPUT);
  DIO_u8SetPinDirection(DIO_u8PORTB ,DIO_u8PIN1 , DIO_u8PIN_INPUT);
  DIO_u8SetPortValue(DIO_u8PORTB , 0xff);
  u8 Local_u8SwitchState;
    while (1) {
    	DIO_u8GetPinValue(DIO_u8PORTB ,DIO_u8PIN1 , &Local_u8SwitchState);
    	if(Local_u8SwitchState == 0)
  	  DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0 , DIO_u8PIN_LOW);
    	else
    	  	  DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0 , DIO_u8PIN_HIGH);
    }
}

