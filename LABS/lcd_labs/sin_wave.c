/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: sohai
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"
#include <util/delay.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

void main() {

    LCD_voidInit();
//    LCD_voidSendString("SOHAIB");
    u8 Local_u8AvailableSpaces = 10;
    u8 x = 0, y = 0 , flag = 0;
    while (1) {
        LCD_voidSendCommand(DISPLAY_CLEAR);
        LCD_voidSetDDRAMAddress(y , x);
        LCD_voidSendString("SOHAIB");
        _delay_ms(300);
        y ^= 1;
        x = flag ? x-1 : x+1;
        if(x == 10) flag = 1;
        if(x == 0) flag = 0;
    }
}

#pragma clang diagnostic pop
