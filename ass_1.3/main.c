/*
 * main.c
 *
 *  Created on: Sep 5, 2023
 *      Author: sohai
 */

#include "avr/io.h"
#include "avr/delay.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define CPU 8000000

u8 SSD_ARR[10] = { 0b00111111, /* 0 */
0b00000110, /* 1 */
0b01011011, /* 2 */
0b01001111, /* 3 */
0b01100110, /* 4 */
0b01101101, /* 5 */
0b01111101, /* 6 */
0b00000111, /* 7 */
0b01111111, /* 8 */
0b01101111 /* 9 */
};

void main() {
	DDRD = 0xff;
	DDRC = 0x03;
	PORTC = 0x03;
	while (1) {
		for (u8 i = 0; i < 10; i++) {
			u8 counter = 50;
			while(counter--){
			PORTD = ~SSD_ARR[i];
			SET_BIT(PORTC, 1);
			CLR_BIT(PORTC, 0);
			_delay_ms(10);

			PORTD = ~SSD_ARR[9-i];
			SET_BIT(PORTC, 0);
			CLR_BIT(PORTC, 1);
			_delay_ms(10);
			}
		}
	}
}
