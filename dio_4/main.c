/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#include "avr/io.h"

#define CPU 8000000
#include "avr/delay.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

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
int main()
{
	u8 LoopCounter;
	DDRA   = 0xFF;
	DDRD   = 0xFF;

	while(1)
	{
		for(int i = 0 ; i < 10; i++){
			PORTA = ~Arr_DecToSeg[i];
			for(LoopCounter=0; LoopCounter<10;LoopCounter++)
				{
					PORTD = ~Arr_DecToSeg[LoopCounter];
					_delay_ms(100);
				}
			}
	}
	return 0;
}
