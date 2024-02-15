/*
 * main.c
 *
 *  Created on: Sep 1, 2023
 *      Author: sohai
 */

#include"avr/io.h"
int main(){
	DDRA =0b00000011;
	PORTA = 0b00000010;
	while(1){}
	return 0;
}

