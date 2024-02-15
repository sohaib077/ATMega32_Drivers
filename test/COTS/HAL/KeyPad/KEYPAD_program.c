//
// Created by sohai on 9/17/2023.
//

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include <avr/io.h>
#include "../../MCAL/DIO/DIO_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "../CLCD/CLCD_interface.h"

u8 KEYPAD_u8ArrValues[][4] = {
        {'7', '8', '9', '/'},
        {'4', '5', '6', '*'},
        {'1', '2', '3', '-'},
        {'%', '0', '=', '+'},
};


void KEYPAD_voidInit() {
    // setting rows to be output
    DIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_R0, DIO_OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_R1, DIO_OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_R2, DIO_OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_R3, DIO_OUTPUT);
    // setting cols to be input
    DIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_C0, DIO_INPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_C1, DIO_INPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_C2, DIO_INPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_C3, DIO_INPUT);
    // setting rows and cols value
    DIO_voidSetPinValue(KEYPAD_PORT, KEYPAD_R0, DIO_HIGH);
    DIO_voidSetPinValue(KEYPAD_PORT, KEYPAD_R1, DIO_HIGH);
    DIO_voidSetPinValue(KEYPAD_PORT, KEYPAD_R2, DIO_HIGH);
    DIO_voidSetPinValue(KEYPAD_PORT, KEYPAD_R3, DIO_HIGH);

    DIO_voidSetPinValue(KEYPAD_PORT, KEYPAD_C0, DIO_HIGH);
    DIO_voidSetPinValue(KEYPAD_PORT, KEYPAD_C1, DIO_HIGH);
    DIO_voidSetPinValue(KEYPAD_PORT, KEYPAD_C2, DIO_HIGH);
    DIO_voidSetPinValue(KEYPAD_PORT, KEYPAD_C3, DIO_HIGH);

}

u8 KEYPAD_u8GetSwitchValue() {

    u8 Local_u8SwitchValue = KEYPAD_NOT_PRESSED_VALUE;
    u8 Local_u8SwitchState;
    for (u8 Local_u8CurrentRow = KEYPAD_ROWS_INIT; Local_u8CurrentRow <= KEYPAD_ROWS_END; ++Local_u8CurrentRow) {
        DIO_voidSetPinValue(KEYPAD_PORT, Local_u8CurrentRow, DIO_LOW);
        for (u8 Local_u8CurrentCol = KEYPAD_COLS_INIT; Local_u8CurrentCol <= KEYPAD_COLS_END; ++Local_u8CurrentCol) {
//            DIO_u8GetPinValue(KEYPAD_PORT, Local_u8CurrentCol, &Local_u8SwitchState);
        	Local_u8SwitchState = DIO_u8GetPinValue(KEYPAD_PORT, Local_u8CurrentCol);
            if (Local_u8SwitchState == 0) {
                _delay_ms(20);
//                DIO_u8GetPinValue(KEYPAD_PORT, Local_u8CurrentCol, &Local_u8SwitchState);
            	Local_u8SwitchState = DIO_u8GetPinValue(KEYPAD_PORT, Local_u8CurrentCol);
                if (Local_u8SwitchState == 0) {
                    Local_u8SwitchValue = KEYPAD_u8ArrValues[Local_u8CurrentRow- KEYPAD_ROWS_INIT][Local_u8CurrentCol- KEYPAD_COLS_INIT];
                    while (Local_u8SwitchState == 0){
//                        DIO_u8GetPinValue(KEYPAD_PORT, Local_u8CurrentCol, &Local_u8SwitchState);
                    	Local_u8SwitchState = DIO_u8GetPinValue(KEYPAD_PORT, Local_u8CurrentCol);

                    }
                    break;
                }
            }
        }
        DIO_voidSetPinValue(KEYPAD_PORT, Local_u8CurrentRow, DIO_HIGH);
        if (Local_u8SwitchValue != KEYPAD_NOT_PRESSED_VALUE) break;
    }

    return Local_u8SwitchValue;
}
