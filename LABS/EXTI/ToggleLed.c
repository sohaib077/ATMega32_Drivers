/*
 * ToggleLed.c
 *
 *  Created on: Oct 8, 2023
 *      Author: sohai
 */


/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: sohai
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/PORT/PORT_config.h"
#include "../MCAL/PORT/PORT_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"
#include <util/delay.h>
#include "../HAL/STEPPER/STEPPER_config.h"
#include "../HAL/STEPPER/STEPPER_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

void Tog_Led();

void main() {
    PORT_voidInit();
    GIE_voidEnable();
    EXTI_u8EXTISetCallBack(EXTI_INT0 , Tog_Led);
    EXTI_u8EXTIEnable(EXTI_INT0 , EXTI_FALLING_EDGE);
    while (1);
}

void Tog_Led() {
    static u8 Local_u8Flag = 1;
    if (Local_u8Flag == 1) {
        DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
        Local_u8Flag = 0;
    } else {
        DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);
        Local_u8Flag = 1;
    }
}

#pragma clang diagnostic pop
