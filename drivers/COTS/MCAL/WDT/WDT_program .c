//
// Created by sohai on 3/4/2024.
//

/****************************************************/
/**************** Name : Sohaib     *****************/
/**************** Date : 3/4/2024 *****************/
/**************** SWC  : WDT     *****************/
/**************** Version : 1.0     *****************/
/****************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "WDT_config.h"
#include "WDT_private.h"
#include "WDT_interface.h"
#include "WDT_register.h"

void WDT_voidEnable(void) {
    SET_BIT(WDTCR, WDTCR_WDE);
}

void WDT_voidDisable(void) {
    WDTCR = (1 << WDTCR_WDE) | (1 << WDTCR_WDTOE);
    WDTCR = 0;
}

u8 WDT_u8Sleep(u8 Copy_u8SleepTime) {
    if (Copy_u8SleepTime > 7) return NOT_OK;
    WDTCR &= 0b11111000;
    WDTCR |= Copy_u8SleepTime;
    return OK;
}
