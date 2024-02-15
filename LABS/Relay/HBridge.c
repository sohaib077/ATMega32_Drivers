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
#include <util/delay.h>


//#define COIL_BLUE	DIO_u8PIN0
//#define COIL_RED	DIO_u8PIN1
//#define COIL_ORANGE	DIO_u8PIN2
//#define COIL_YELLOW	DIO_u8PIN3

void main() {
	DIO_u8SetPinDirection(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA , DIO_u8PIN1 , DIO_u8PIN_OUTPUT);
//	DIO_u8SetPinDirection(DIO_u8PORTA , DIO_u8PIN2 , DIO_u8PIN_OUTPUT);
//	DIO_u8SetPinDirection(DIO_u8PORTA , DIO_u8PIN3 , DIO_u8PIN_OUTPUT);
	while(1){
	DIO_u8SetPinValue(DIO_u8PORTA , DIO_u8PIN1 , DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_HIGH);
	_delay_ms(200);
	DIO_u8SetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA , DIO_u8PIN1 , DIO_u8PIN_HIGH);
	_delay_ms(200);
	}
}

