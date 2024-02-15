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
#include <string.h>

static u8 Local_u8ReceivedData[3];

void receivingDataCallBack();
void sendDataCallBack();

void main() {
	PORT_voidInit();
	USART_voidInit();
	GIE_voidEnable();
	while (1) {
			USART_u8ReceiveStringAsync(&Local_u8ReceivedData,3,
					&receivingDataCallBack);
	}
}

void receivingDataCallBack() {

	if (!strcmp(Local_u8ReceivedData , "aaa")) {
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
		USART_u8SendDataAsync('o');
	} else if (!strcmp(Local_u8ReceivedData , "bbb")) {
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);
		USART_u8SendDataAsync('c');
	}
}

void sendDataCallBack() {
	USART_u8SendDataAsync('D');

}
