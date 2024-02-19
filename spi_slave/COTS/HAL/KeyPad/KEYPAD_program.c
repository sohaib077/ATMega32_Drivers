//
// Created by sohai on 9/17/2023.
//

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include <avr/io.h>
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../LCD/LCD_interface.h"

u8 KEYPAD_u8ArrValues[][4] = {
        {'7', '8', '9', '/'},
        {'4', '5', '6', '*'},
        {'1', '2', '3', '-'},
        {'%', '0', '=', '+'},
};


void KEYPAD_voidInit() {
    // setting rows to be output
    DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_R0, DIO_u8PIN_OUTPUT);
    DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_R1, DIO_u8PIN_OUTPUT);
    DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_R2, DIO_u8PIN_OUTPUT);
    DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_R3, DIO_u8PIN_OUTPUT);
    // setting cols to be input
    DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_C0, DIO_u8PIN_INPUT);
    DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_C1, DIO_u8PIN_INPUT);
    DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_C2, DIO_u8PIN_INPUT);
    DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_C3, DIO_u8PIN_INPUT);
    // setting rows and cols value
    DIO_u8SetPortValue(KEYPAD_PORT, DIO_u8PORT_HIGH);
}

u8 KEYPAD_u8GetSwitchValue() {

    u8 Local_u8SwitchValue = KEYPAD_NOT_PRESSED_VALUE;
    u8 Local_u8SwitchState;
    // Iterating over rows
    for (u8 Local_u8CurrentRow = KEYPAD_ROWS_INIT;
         Local_u8CurrentRow <= KEYPAD_ROWS_END; ++Local_u8CurrentRow) {

        // Applying the pattern
        DIO_u8SetPinValue(KEYPAD_PORT, Local_u8CurrentRow, DIO_u8PIN_LOW);

        // Iterating over cols
        for (u8 Local_u8CurrentCol = KEYPAD_COLS_INIT; Local_u8CurrentCol <= KEYPAD_COLS_END; ++Local_u8CurrentCol) {
            // Check if the key is pressed
            DIO_u8GetPinValue(KEYPAD_PORT, Local_u8CurrentCol, &Local_u8SwitchState);

            // Handling the bouncing
            if (Local_u8SwitchState == KEYPAD_SWITCH_ON) {
                _delay_ms(20);
                DIO_u8GetPinValue(KEYPAD_PORT, Local_u8CurrentCol, &Local_u8SwitchState);
                if (Local_u8SwitchState == KEYPAD_SWITCH_ON) {
                    Local_u8SwitchValue = KEYPAD_u8ArrValues[Local_u8CurrentRow - KEYPAD_ROWS_INIT][Local_u8CurrentCol -
                                                                                                    KEYPAD_COLS_INIT];
                    while (Local_u8SwitchState == KEYPAD_SWITCH_ON)
                        DIO_u8GetPinValue(KEYPAD_PORT, Local_u8CurrentCol, &Local_u8SwitchState);

                    break;
                }
            }
        }

        DIO_u8SetPinValue(KEYPAD_PORT, Local_u8CurrentRow, DIO_u8PIN_HIGH);
        if (Local_u8SwitchValue != KEYPAD_NOT_PRESSED_VALUE)
            break;
    }

    return Local_u8SwitchValue;
}
