/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: sohai
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KeyPad/KEYPAD_config.h"
#include "../HAL/KeyPad/KEYPAD_interface.h"
#include <util/delay.h>

#define NOT_USED 0
#define USED 1
#define FALSE 0
#define TRUE 1

s64 Global_u64Operand1 = NULL;
s32 Global_u64Operand2 = NULL;
s64 Global_u64Ans = NULL;
u8 Global_u8Operator = NULL;
u8 Global_u8DigitsNumber = 0;
u8 Global_u8IsAnswered = FALSE;
u8 Global_u8Operand1State = NOT_USED;
u8 Global_u8Operand2State = NOT_USED;
u8 Global_u8NegativeFlag = FALSE;

void ClearDisplay();
void ResetLcd(u8 Copy_u8ClearFlag , u8 Copy_u8DigitsNumber);
void DisplayDataWithShiftingIfNeeded(u8 Copy_u8Data);
void HandlingOperands(u8 Copy_u8Data);
void DisplayAnswer();
u8 GetDigitsNumber(s64 Copy_s64Number);
void main() {
	LCD_voidInit();
	KEYPAD_voidInit();
	u8 Local_u8SwitchValue;
	while (1) {
		Local_u8SwitchValue = KEYPAD_u8GetSwitchValue();
		if (Local_u8SwitchValue != KEYPAD_NOT_PRESSED_VALUE) {
			if (Local_u8SwitchValue == '=')
				DisplayAnswer();
			else if (Local_u8SwitchValue == '%')
				ResetLcd(1 , 0);
			else {
				DisplayDataWithShiftingIfNeeded(Local_u8SwitchValue);
				HandlingOperands(Local_u8SwitchValue);
			}
		}
//			LCD_voidSendData(Local_u8SwitchValue);
	}
}

void ClearDisplay() {
	LCD_voidSendCommand(DISPLAY_CLEAR);
}
void ResetLcd(u8 Copy_u8ClearFlag, u8 Copy_u8DigitsNumber) {
	if (Copy_u8ClearFlag != 0)
		ClearDisplay();
	Global_u64Operand1 = NULL;
	Global_u64Operand2 = NULL;
	Global_u64Ans = NULL;
	Global_u8Operator = NULL;
	Global_u8DigitsNumber = Copy_u8DigitsNumber;
	Global_u8IsAnswered = FALSE;
	Global_u8Operand1State = NOT_USED;
	Global_u8Operand2State = NOT_USED;
	Global_u8NegativeFlag = FALSE;

}

u8 CheckIfNumber(u8 Copy_u8Data) {
	return !(Copy_u8Data > '9' || Copy_u8Data < '0');
}

void DisplayDataWithShiftingIfNeeded(u8 Copy_u8Data) {
	if (++Global_u8DigitsNumber > 16)
		LCD_voidSendCommand(SHIFT_DISPLAY_LEFT);

	if (Global_u8IsAnswered != NULL
			&& CheckIfNumber(Copy_u8Data) && Global_u8Operator == NULL)
		ResetLcd(1, 0);

	LCD_voidSendData(Copy_u8Data);
}

void HandlingOperands(u8 Copy_u8Data) {
	if ((Global_u8DigitsNumber == 1
			|| (Global_u8Operator != NULL && Global_u8Operand2State == NOT_USED))
			&& Copy_u8Data == '-') {
		Global_u8NegativeFlag = TRUE;
		return;
	}

	if (Global_u8Operator == NULL && !CheckIfNumber(Copy_u8Data))
		Global_u8Operator = Copy_u8Data;
	else if (Global_u8Operator == NULL) {
		Global_u64Operand1 =
				Global_u64Operand1 == NULL ?
						(Global_u64Operand1 + (Copy_u8Data - '0')) :
						Global_u64Operand1 * 10 + (Copy_u8Data - '0');
		Global_u8Operand1State = USED;
	} else {
		Global_u64Operand2 =
				Global_u64Operand2 == NULL ?
						(Global_u64Operand2 + (Copy_u8Data - '0')) :
						Global_u64Operand2 * 10 + (Copy_u8Data - '0');
		Global_u8Operand2State = USED;
	}
	if (Global_u8NegativeFlag == TRUE) {
		if (Global_u8DigitsNumber == 2)
			Global_u64Operand1 *= -1;
		else
			Global_u64Operand2 *= -1;
		Global_u8NegativeFlag = FALSE;
	}
}
void DisplayAnswer() {
	if (Global_u8Operator == '/' && Global_u64Operand2 == 0) {
		ResetLcd(1, 5);
		LCD_voidSendString("ERROR");
		Global_u8IsAnswered = 1;
		return;
	}
	switch (Global_u8Operator) {
	case '+':
		Global_u64Ans = Global_u64Operand1 + Global_u64Operand2;
		break;
	case '-':
		Global_u64Ans = Global_u64Operand1 - Global_u64Operand2;
		break;
	case '/':
		Global_u64Ans = Global_u64Operand1 / Global_u64Operand2;
		break;
	case '*':
		Global_u64Ans = Global_u64Operand1 * Global_u64Operand2;
		break;
	default:
		Global_u64Ans = Global_u64Operand1;
	}
	ClearDisplay();

	LCD_voidWriteNumber(Global_u64Ans);
	u64 Local_u64Temp = Global_u64Ans;
	ResetLcd(0 , GetDigitsNumber(Local_u64Temp));
	Global_u64Operand1 = Local_u64Temp;
	Global_u8IsAnswered = 1;
}

u8 GetDigitsNumber(s64 Copy_s64Number) {
	u8 Local_digitsNumber = 1 * (Copy_s64Number == 0);
	while (Copy_s64Number != 0) {
		Local_digitsNumber++;
		Copy_s64Number /= 10;
	}
	return Local_digitsNumber;
}
