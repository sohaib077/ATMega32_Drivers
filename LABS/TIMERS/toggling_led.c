/*
 * toggling_led.c
 *
 *  Created on: Oct 15, 2023
 *      Author: sohai
 */


/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: sohai
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/PORT/PORT_interface.h"
#include "../MCAL/TIMERS/TIMERS_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include <util/delay.h>



void TIMER0_voidCallBack();
void ADC_voidCallBack(u32 Copy_u16CopyDigitalValue);
void main() {
	PORT_voidInit();
	GIE_voidEnable();
	TIMERS_voidTimer0Init();
//    TIMERS_u8Timer0SetCallBack(&TIMER0_voidCallBack);
    TIMERS_u8Timer0CTCSetCallBack(&TIMER0_voidCallBack);
	while (1){}

}
void TIMER0_voidCallBack(){
	static u8 Local_u8LedState = 0;
    if(Local_u8LedState == 0)
        DIO_u8SetPinValue(DIO_u8PORTC , DIO_u8PIN0 , DIO_u8PIN_HIGH);
    else
        DIO_u8SetPinValue(DIO_u8PORTC , DIO_u8PIN0 , DIO_u8PIN_LOW);
    Local_u8LedState = !Local_u8LedState;
}
