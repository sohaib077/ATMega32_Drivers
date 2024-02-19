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

void main() {
	PORT_voidInit();
	SPI_VoidMasterInit();
	u8 Local_u8ReceivedData = 0;
	u8 Local_u8Data = 1;
	while (1) {
		SPI_VoidTransceiveSync(Local_u8Data, &Local_u8ReceivedData);
		_delay_ms(1000);
		Local_u8Data = ! Local_u8Data;
	}
}
//void main() {
//	PORT_voidInit();
//	SPI_VoidSlaveInit();
//	u8 Local_u8ReceivedData = 0;
//	while (1) {
//		SPI_VoidTransceiveSync(2, &Local_u8ReceivedData);
//		if (Local_u8ReceivedData == 1)
//			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
//		else if (Local_u8ReceivedData == 0)
//			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);
//		_delay_ms(10);
//	}
//}

