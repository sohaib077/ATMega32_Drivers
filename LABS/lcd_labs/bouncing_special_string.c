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

u8 Local_pu8SpecialStringData[][8] = {{
                                              0b00000100,
                                              0b00001010,
                                              0b00001001,
                                              0b00011111,
                                              0b00001000,
                                              0b00001000,
                                              0,
                                              0,
                                      },
                                      {
                                              0,
                                              0,
                                              0,
                                              0b00010001,
                                              0b00010010,
                                              0b00010100,
                                              0b00011000,
                                              0,
                                      },
                                      {
                                              0,
                                              4,
                                              4,
                                              0xff,
                                              0,
                                              0b00001010,
                                              0,
                                              0,
                                      },
                                      {
                                              0,
                                              0b00010010,
                                              0b00010010,
                                              0xff,
                                              0,
                                              0b00001100,
                                              0,
                                              0,
                                      },
};
void main() {

    LCD_voidInit();
//    LCD_voidSendString("SOHAIB");
    u8 Local_u8AvailableSpaces = 12;
    u8 x = 0, y = 0 , flag = 0;
    while (1) {
        LCD_voidSendCommand(DISPLAY_CLEAR);
        LCD_voidSetDDRAMAddress(y ,x);
        LCD_voidWriteSpecialString(Local_pu8SpecialStringData ,  4, LCD_WRITE_FROM_RIGHT , x , y);
        _delay_ms(300);
        y ^= 1;
        x = flag ? x-1 : x+1;
        if(x == 12) flag = 1;
        if(x == 0) flag = 0;
    }
}

#pragma clang diagnostic pop
