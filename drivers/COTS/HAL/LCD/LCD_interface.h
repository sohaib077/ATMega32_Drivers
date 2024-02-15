//
// Created by sohai on 9/13/2023.
//

#ifndef LCD_PROGRAM_C_LCD_INTERFACE_H
#define LCD_PROGRAM_C_LCD_INTERFACE_H

#define LCD_CHARACTERS_PER_LINE

void LCD_voidSendCommand(u8 Copy_u8Command);

void LCD_voidSendData(u8 Copy_u8Data);

void LCD_voidSendString(pu8 Copy_pu8Data);

void LCD_voidInit();

void LCD_voidShiftDisplayRight(u8 Copy_u8ShiftingNumber);

void LCD_voidShiftDisplayLeft(u8 Copy_u8ShiftingNumber);

void LCD_voidSetDDRAMAddress(u8 x, u8 y);

void LCD_voidWriteSpecialCharacter(pu8 Copy_pu8Character, u8 Copy_u8CharacterPos, u8 Copy_u8X, u8 Copy_u8Y, u8 Copy_u8Direction);

void LCD_voidWriteSpecialString(u8 Copy_pu8String[][8], u8 Copy_u8NumberOfCharacters, u8 Copy_u8Direction, u8 Copy_u8X, u8 Copy_u8Y);

void LCD_voidWriteNumber(f64 Copy_s64Number);

#endif //LCD_PROGRAM_C_LCD_INTERFACE_H
