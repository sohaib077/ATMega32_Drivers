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
	int i = 0 , x=0;
	i== 0 ? x++ : x--;
	DDRA = 0b00000011;
	PORTA = (i == 0) ? 0b00000001 : 0;
	_delay_ms(2000);
	PORTA = 0b00000010;
	_delay_ms(2000);
	PORTA = 0b00000000;
	while(1){};
	return 0;
}
