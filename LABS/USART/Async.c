/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: sohai
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/PORT/PORT_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"
#include <util/delay.h>

static u8 Local_u8ReceivedData;

void receivingDataCallBack();

void main() {
	PORT_voidInit();
	USART_voidInit();
	GIE_voidEnable();
	while (1) {
			USART_u8ReceiveDataAsync(&Local_u8ReceivedData,
					&receivingDataCallBack);
	}
}

void receivingDataCallBack() {
	if (Local_u8ReceivedData == '1') {
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
		USART_u8SendDataAsync('o');
	} else if (Local_u8ReceivedData == '2') {
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);
		USART_u8SendDataAsync('c');
	}

}
