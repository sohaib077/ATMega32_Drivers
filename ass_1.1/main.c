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

u8 Arr_DecToSeg[10] = {0b00111111,   /* 0 */
                       0b00000110,   /* 1 */
                       0b01011011,   /* 2 */
                       0b01001111,   /* 3 */
                       0b01100110,   /* 4 */
                       0b01101101,   /* 5 */
                       0b01111101,   /* 6 */
                       0b00000111,   /* 7 */
                       0b01111111,   /* 8 */
                       0b01101111    /* 9 */
					  };
/*
  Green  -> 15s
  Yellow -> 3s
  Red 	 -> 10s
 */
void counter(u8 seconds);

void main(){
	DDRA = 0xff;  /* LEDS  */
	DDRD = 0xff;  /* Tens SSD */
	DDRC = 0xff;  /* Ones SSD */
	while(1){
		SET_BIT(PORTA , 2);
		counter(15);
		CLR_BIT(PORTA , 2);

		SET_BIT(PORTA , 1);
		counter(3);
		CLR_BIT(PORTA , 1);

		SET_BIT(PORTA , 0);
		counter(10);
		CLR_BIT(PORTA , 0);
	}
}

void counter(u8 seconds) {
	for (u8 j = seconds; j > 0; j--) {
		PORTD = ~Arr_DecToSeg[(j % 10)];
		PORTC = ~Arr_DecToSeg[(j/10)];
		_delay_ms(1000);
	}
}
