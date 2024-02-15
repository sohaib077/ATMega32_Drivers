#include "../../LIB//STD_TYPES.h"
#include "../../LIB//BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"

u8 static portChecker(u8 Copy_u8Port) {
    return Copy_u8Port > DIO_u8PORTD;
}

u8 static pinChecker(u8 Copy_u8Pin) {
    return Copy_u8Pin > DIO_u8PIN7;
}

u8 static directionChecker(u8 Copy_u8Direction) {
    return Copy_u8Direction > DIO_u8PIN_OUTPUT;
}

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction) {
    if (portChecker(Copy_u8Port) || pinChecker(Copy_u8Pin)
        || directionChecker(Copy_u8Direction))
        return 1;
    if (Copy_u8Direction == DIO_u8PIN_OUTPUT)
        switch (Copy_u8Port) {
            case DIO_u8PORTA:
                SET_BIT(DDRA, Copy_u8Pin);
                break;
            case DIO_u8PORTB:
                SET_BIT(DDRB, Copy_u8Pin);
                break;
            case DIO_u8PORTC:
                SET_BIT(DDRC, Copy_u8Pin);
                break;
            case DIO_u8PORTD:
                SET_BIT(DDRD, Copy_u8Pin);
                break;
        }
    else
        switch (Copy_u8Port) {
            case DIO_u8PORTA:
                CLR_BIT(DDRA, Copy_u8Pin);
                break;
            case DIO_u8PORTB:
                CLR_BIT(DDRB, Copy_u8Pin);
                break;
            case DIO_u8PORTC:
                CLR_BIT(DDRC, Copy_u8Pin);
                break;
            case DIO_u8PORTD:
                CLR_BIT(DDRD, Copy_u8Pin);
                break;
        }

    return 0;
}

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction) {
    if (portChecker(Copy_u8Port) )
        return 1;
    switch (Copy_u8Port) {
        case DIO_u8PORTA:
            DDRA = Copy_u8Direction;
            break;
        case DIO_u8PORTB:
            DDRB = Copy_u8Direction;
            break;
        case DIO_u8PORTC:
            DDRC = Copy_u8Direction;
            break;
        case DIO_u8PORTD:
            DDRD = Copy_u8Direction;
            break;
    }
    return 0;

}

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value) {
    if (portChecker(
            Copy_u8Port) || pinChecker(Copy_u8Pin) || Copy_u8Value > DIO_u8PIN_HIGH)
        return 1;
    if (Copy_u8Value == DIO_u8PIN_HIGH)
        switch (Copy_u8Port) {
            case DIO_u8PORTA:
                SET_BIT(PORTA, Copy_u8Pin);
                break;
            case DIO_u8PORTB:
                SET_BIT(PORTB, Copy_u8Pin);
                break;
            case DIO_u8PORTC:
                SET_BIT(PORTC, Copy_u8Pin);
                break;
            case DIO_u8PORTD:
                SET_BIT(PORTD, Copy_u8Pin);
                break;
        }
    else
        switch (Copy_u8Port) {
            case DIO_u8PORTA:
                CLR_BIT(PORTA, Copy_u8Pin);
                break;
            case DIO_u8PORTB:
                CLR_BIT(PORTB, Copy_u8Pin);
                break;
            case DIO_u8PORTC:
                CLR_BIT(PORTC, Copy_u8Pin);
                break;
            case DIO_u8PORTD:
                CLR_BIT(PORTD, Copy_u8Pin);
                break;
        }

    return 0;
}

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value) {
    if (portChecker(Copy_u8Port) )
        return 1;

    switch (Copy_u8Port) {
        case DIO_u8PORTA:
            PORTA = Copy_u8Value;
            break;
        case DIO_u8PORTB:
            PORTB = Copy_u8Value;
            break;
        case DIO_u8PORTC:
            PORTC = Copy_u8Value;
            break;
        case DIO_u8PORTD:
            PORTD = Copy_u8Value;
            break;
    }
    return 0;

}

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, pu8 Copy_pu8Value) {
    if (portChecker(
            Copy_u8Port) || pinChecker(Copy_u8Pin) || Copy_pu8Value == NULL)
        return 1;
    switch (Copy_u8Port) {
        case DIO_u8PORTA:
            *Copy_pu8Value = GET_BIT(PINA, Copy_u8Pin);
            break;
        case DIO_u8PORTB:
            *Copy_pu8Value = GET_BIT(PINB, Copy_u8Pin);
            break;
        case DIO_u8PORTC:
            *Copy_pu8Value = GET_BIT(PINC, Copy_u8Pin);
            break;
        case DIO_u8PORTD:
            *Copy_pu8Value = GET_BIT(PIND, Copy_u8Pin);
            break;
    }
    return 0;
}
