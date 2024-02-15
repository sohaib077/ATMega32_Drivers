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
	DDRA = 0xFF;
	while(1){
		PORTA = 0x91;
		_delay_ms(300);
		PORTA = 0x4A;
		_delay_ms(300);
		PORTA = 0x24;
		_delay_ms(300);
	}
	return 0;
}

