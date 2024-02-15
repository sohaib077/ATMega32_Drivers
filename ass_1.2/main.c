/*
 * main.c
 *
 *  Created on: Sep 4, 2023
 *      Author: sohai
 */

#include "avr/io.h"
#include "avr/delay.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define CPU 8000000
#define LEDS 8

void flashing();
void shift_left();
void shift_right();
void converging();
void diverging();
void ping_pong();
void converging_diverging();

void main() {
	PORTC = 0xff;
	DDRD = 0xff;
	u8 x;
	while (1) {
//		u8 x = GET_BIT(PINC , 0);
		x = ~PINC;
		switch (x) {
		case 1:
			flashing();
			break;
		case 2:
			shift_left();
			break;
		case 4:
			shift_right();
			break;
		case 0b00001000:
			converging();
			break;
		case 0b00010000:
			diverging();
			break;
		case 0b00100000:
			ping_pong();
			break;
		case 0b01000000:
			 converging_diverging();
			break;
		default:
			PORTD = 0x00;
			break;
		}
	}

}

void flashing() {
	SET_BIT(PORTD, 0);
	_delay_ms(500);
	CLR_BIT(PORTD, 0);
	_delay_ms(500);
}
void shift_left() {
	for (u8 i = 0; i < LEDS; i++) {
		SET_BIT(PORTD, i);
		_delay_ms(250);
		CLR_BIT(PORTD, i);
		_delay_ms(250);
	}
}
void shift_right() {
	for (u8 i = 0; i < LEDS; i++) {
		SET_BIT(PORTD, LEDS-i-1);
		_delay_ms(250);
		CLR_BIT(PORTD, LEDS-i-1);
		_delay_ms(250);
	}
}
void converging() {
	PORTD = 0x00;
	for (u8 i = 0; i < LEDS / 2; i++) {
		SET_BIT(PORTD, LEDS-i-1);
		SET_BIT(PORTD, i);
		_delay_ms(300);
	}
}
void diverging() {
	PORTD = 0x00;
	for (u8 i = 0; i < LEDS / 2; i++) {
		SET_BIT(PORTD, LEDS/2+i);
		SET_BIT(PORTD, LEDS/2-i-1);
		_delay_ms(300);
	}
}
void ping_pong() {
	shift_right();
	shift_left();
}
void converging_diverging() {
	converging();
	for (u8 i = 0; i < LEDS / 2; i++) {
		CLR_BIT(PORTD, LEDS/2+i);
		CLR_BIT(PORTD, LEDS/2-i-1);
		_delay_ms(300);
	}
}

