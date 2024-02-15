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
#include "../HAL/KeyPad/KEYPAD_config.h"
#include "../HAL/KeyPad/KEYPAD_interface.h"
#include <util/delay.h>

void main() {
    LCD_voidInit();
    KEYPAD_voidInit();
    u8 Local_u8SwitchValue;
    while (1) {
        Local_u8SwitchValue = KEYPAD_u8GetSwitchValue();
        if (Local_u8SwitchValue != KEYPAD_NOT_PRESSED_VALUE)
            LCD_voidSendData(Local_u8SwitchValue);
    }
}

