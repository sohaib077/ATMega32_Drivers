//
// Created by sohai on 3/4/2024.
//

/****************************************************/
/**************** Name : Sohaib     *****************/
/**************** Date : 3/4/2024 *****************/
/**************** SWC  : WDT     *****************/
/**************** Version : 1.0     *****************/
/****************************************************/

#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H


/* Watchdog Timer Prescale Select */
#define WDT_16_3_MS_PRESCALER       0   /* (Vcc = 3v  --> 17.1 ms)    (Vcc = 5v  --> 16.3 ms) */
#define WDT_32_5_MS_PRESCALER       1   /* (Vcc = 3v  --> 34.3 ms)    (Vcc = 5v  --> 32.5 ms) */
#define WDT_65_0_MS_PRESCALER       2   /* (Vcc = 3v  --> 68.5 ms)    (Vcc = 5v  --> 65.0 ms) */
#define WDT_0_13_S_PRESCALER        3   /* (Vcc = 3v  --> 0.14  s)    (Vcc = 5v  --> 0.13  s) */
#define WDT_0_26_S_PRESCALER        4   /* (Vcc = 3v  --> 0.27  s)    (Vcc = 5v  --> 0.26  s) */
#define WDT_0_52_S_PRESCALER        5   /* (Vcc = 3v  --> 0.55  s)    (Vcc = 5v  --> 0.52  s) */
#define WDT_1_0_S_PRESCALER         6   /* (Vcc = 3v  --> 1.1   s)    (Vcc = 5v  --> 1.0   s) */
#define WDT_2_1_S_PRESCALER         7   /* (Vcc = 3v  --> 2.2   s)    (Vcc = 5v  --> 2.1   s) */


void WDT_voidEnable(void);

void WDT_voidDisable(void);

u8 WDT_u8Sleep(u8 Copy_u8SleepTime);


#endif //WDT_INTERFACE_H