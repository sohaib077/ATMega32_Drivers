#include"avr/io.h"
int main(){
	DDRA =0b00000001;
	PORTA = 0b00000001;
	while(1){}
	return 0;
}
