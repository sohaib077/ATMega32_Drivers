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
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"
#include <util/delay.h>
#include <string.h>

static u8 Global_u8ReceivedData[3];
void SPI_voidCallBack();

void main() {
	PORT_voidInit();
	SPI_VoidSlaveInit();
	u8 Local_u8ReceivedData = 0;
	while (1) {
		SPI_u8TransceiveSync(2, &Local_u8ReceivedData);
		if (Local_u8ReceivedData == 1)
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
		else if (Local_u8ReceivedData == 0)
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);
		_delay_ms(10);
	}
}


void SPI_voidCallBack() {
	DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_HIGH);

	if (!strcmp(Global_u8ReceivedData , "aaa"))
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
	else if (!strcmp(Global_u8ReceivedData , "bbb"))
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);
}

