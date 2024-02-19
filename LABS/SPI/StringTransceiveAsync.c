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

static u8 Global_u8ReceivedData = 0;
void SPI_voidCallBack();

u8 Local_u8Data = 1;
void main() {
	PORT_voidInit();
	SPI_VoidMasterInit();
	GIE_voidEnable();
	u8 Local_u8ReceivedData[3] ;
	u8* Local_pu8TransmittedData = "aaa";
	while (1) {
		SPI_u8TransceiveStringAsync(Local_pu8TransmittedData, &Local_u8ReceivedData,3 ,
				SPI_voidCallBack);
		Local_u8Data = !Local_u8Data;
		Local_pu8TransmittedData = Local_u8Data ? "bbb" : "aaa";
		_delay_ms(100);

	}
}


void SPI_voidCallBack() {}

//------------------------------------------ SLAVE ----------------------------//


static u8 Global_u8ReceivedData[3];
void SPI_voidCallBack();

void main() {
	PORT_voidInit();
	SPI_VoidSlaveInit();
	GIE_voidEnable();
	while (1) {
		SPI_u8TransceiveStringAsync("ccc", &Global_u8ReceivedData, 3 ,SPI_voidCallBack);
		_delay_ms(100);
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



