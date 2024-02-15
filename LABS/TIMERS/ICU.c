/*
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
#include "../MCAL/TIMERS/TIMERS_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"
#include <util/delay.h>

#define F_CPU 8000000UL
static volatile u16 Period_Ticks = 0;
static volatile s16 On_Ticks = 0;
void ICU_SW();
void main() {
	PORT_voidInit();
	LCD_voidInit();
	TIMER0_voidInit();
	TIMER1_voidInit();
	EXTI_u8EXTIEnable(EXTI_INT0, EXTI_ON_CHANGE);
	EXTI_u8EXTISetCallBack(EXTI_INT0, ICU_SW);
	GIE_voidEnable();
	u8 Local_u8Flag = 0;
	while (1) {
		while ((Period_Ticks == 0 || On_Ticks == 0));
		if (!Local_u8Flag) {
			LCD_voidSetDDRAMAddress(0, 0);
			LCD_voidSendString("Period = ");
			LCD_voidWriteNumber(Period_Ticks);
			LCD_voidSetDDRAMAddress(1, 0);
			LCD_voidSendString("On period = ");
			LCD_voidWriteNumber(On_Ticks);
			Local_u8Flag = 1;
		}
	}

}
void ICU_SW() {
	static volatile u8  Local_u8Counter = 0;
	if (Local_u8Counter == 0) {
		TIMER1_voidSetTimerValue(0);
	} else if (Local_u8Counter == 1) {
		On_Ticks = TIMER1_u16ReadTimerValue();
	} else if(Local_u8Counter == 2){
		Period_Ticks = TIMER1_u16ReadTimerValue() ;
		GIE_voidDisable();
	}
	Local_u8Counter++;
}



