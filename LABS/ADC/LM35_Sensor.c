/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: sohai
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/ADC/ADC_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KeyPad/KEYPAD_config.h"
#include "../HAL/KeyPad/KEYPAD_interface.h"
#include <util/delay.h>

void main() {
	PORT_voidInit();
	LCD_voidInit();
	ADC_voidInit();
	u32 Local_u32DigitalValue;
	u32 Local_u32AnalogValue;
	u32 Local_u32TempValue;
	u32 Local_u32Flag;
	while (1) {
		ADC_u16ReadSynchronous(ADC_CH0, &Local_u32DigitalValue);
			Local_u32AnalogValue = (Local_u32DigitalValue * 5000) / 1024;
			Local_u32TempValue = Local_u32AnalogValue / 10;
		if (Local_u32Flag != Local_u32TempValue) {
			Local_u32Flag = Local_u32TempValue;
			LCD_voidSendCommand(1);
			LCD_voidWriteNumber(Local_u32TempValue);
		}

	}

}

/*  ASYNCHRONOUS   */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/ADC/ADC_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KeyPad/KEYPAD_config.h"
#include "../HAL/KeyPad/KEYPAD_interface.h"
#include <util/delay.h>



static u32 ADC_u16DigitalValue = ADC_INITIAL_DIGITAL_VALUE;

void ADC_voidCallBack(u32 Copy_u16CopyDigitalValue);
void main() {
	LCD_voidInit();
	ADC_voidInit();
	GIE_voidEnable();
//	PORT_voidInit();
	u32 Local_u32AnalogValue;
	u32 Local_u32TempValue;
	u32	Local_u32Flag = ADC_INITIAL_DIGITAL_VALUE;
	while (1) {
		ADC_u16ReadAsynchronous(ADC_CH0,ADC_voidCallBack);
		if(ADC_u16DigitalValue != Local_u32Flag){
			Local_u32AnalogValue = (ADC_u16DigitalValue * 5000) / 1024;
			Local_u32TempValue = Local_u32AnalogValue / 10;
			LCD_voidSendCommand(DISPLAY_CLEAR);
			LCD_voidWriteNumber(Local_u32TempValue);
			Local_u32Flag = ADC_u16DigitalValue ;
//			ADC_u16DigitalValue = ADC_INITIAL_DIGITAL_VALUE;
		}
	}

}
void ADC_voidCallBack(u32 Copy_u16CopyDigitalValue){
	ADC_u16DigitalValue = Copy_u16CopyDigitalValue;
}


