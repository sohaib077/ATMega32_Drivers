/*********************************************************/
/***********		Author: Amgad Samir 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: CLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/

#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set command to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS pin to high for data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set Data to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidInit(void)
{
	/*Wait for more than 30 ms*/
	_delay_ms(40);

	/*Function set command: 2 lines, 5*8 Font size*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on off control: display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/*Clear display*/
	CLCD_voidSendCommand(1);
}
