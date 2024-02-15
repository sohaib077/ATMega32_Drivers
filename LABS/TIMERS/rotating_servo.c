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
#include "../MCAL/ADC/ADC_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"
#include <util/delay.h>

#define F_CPU 8000000UL

void TIMER0_voidCallBack();
void ADC_voidCallBack(u32 Copy_u16CopyDigitalValue);
void main() {
	PORT_voidInit();
	LCD_voidInit();
	ADC_voidInit();
	TIMERS_voidTimer1Init();
	u32 Local_u32DigitalValue;
	u16 Local_u16ServoValue;

	while (1) {
		ADC_u16ReadSynchronous(ADC_CH0, &Local_u32DigitalValue);
		Local_u16ServoValue = ((Local_u32DigitalValue * 1000UL) / 1023) + 999;
		TIMERS_voidTimer1SetCompareMatchValueA(Local_u32DigitalValue);
		LCD_voidSendCommand(1);
		LCD_voidWriteNumber(Local_u32DigitalValue);
//        Local_u8Counter++;
//        _delay_ms(100);
	}

}
void TIMER0_voidCallBack() {
	static u8 Local_u8LedState = 0;
	if (Local_u8LedState == 0)
		DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_HIGH);
	else
		DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_LOW);
	Local_u8LedState = !Local_u8LedState;
}
