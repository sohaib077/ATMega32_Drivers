/*
 * main.c
 *
 *  Created on: Sep 2, 2023
 *      Author: sohai
 */
#include"avr/io.h"
#include"avr/delay.h"
#define F_CPU 8000000

int main(){
	DDRA = 0x07;
	while(1){
		PORTA = 0x01;
		_delay_ms(500);
		PORTA = 0x02;
		_delay_ms(500);
		PORTA = 0x04;
		_delay_ms(500);
	}
	return 0;
}
