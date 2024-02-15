/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: sohai
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/CLCD/CLCD_config.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/KeyPad/KEYPAD_config.h"
#include "../HAL/KeyPad/KEYPAD_interface.h"
#include <util/delay.h>

int main() {
    CLCD_voidInit();
    KEYPAD_voidInit();
    u8 Local_u8SwitchValue;
    while (1) {
        Local_u8SwitchValue = KEYPAD_u8GetSwitchValue();
        if (Local_u8SwitchValue != KEYPAD_NOT_PRESSED_VALUE)
            CLCD_voidSendData(Local_u8SwitchValue);
    }
    return 0;
}

