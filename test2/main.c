/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: sohai
 */
//#define COIL_BLUE	DIO_u8PIN0
//#define COIL_RED	DIO_u8PIN1
//#define COIL_ORANGE	DIO_u8PIN2
//#define COIL_YELLOW	DIO_u8PIN3
#include"avr/io.h"
#include"avr/delay.h"
#define F_CPU 8000000
int main() {
	return 0;
	//	DIO_u8SetPinDirection(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_OUTPUT);
	//	DIO_u8SetPinDirection(DIO_u8PORTA , DIO_u8PIN1 , DIO_u8PIN_OUTPUT);
	//	DIO_u8SetPinDirection(DIO_u8PORTA , DIO_u8PIN2 , DIO_u8PIN_OUTPUT);
	//	DIO_u8SetPinDirection(DIO_u8PORTA , DIO_u8PIN3 , DIO_u8PIN_OUTPUT);
	DDRA = 0xff;
	while (1) {
		//	DIO_u8SetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_HIGH);
		PORTA = 1;
		_delay_ms(2000);
		PORTA = 0;
		//	DIO_u8SetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_LOW);
		_delay_ms(2000);
	}
}

