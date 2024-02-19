//
// Created by sohai on 10/14/2023.
//

/****************************************************/
/**************** Name : Sohaib     *****************/
/**************** Date : 10/14/2023 *****************/
/**************** SWC  : TIMERS     *****************/
/**************** Version : 1.0     *****************/
/****************************************************/

#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

#define TIMERS_T0_NORMAL_MODE      0
#define TIMERS_T0_PWM_MODE         1
#define TIMERS_T0_CTC_MODE         2
#define TIMERS_T0_FAST_PWM_MODE    3

#define TIMERS_T0_NO_CLOCK                    0
#define TIMERS_T0_NO_PRESCALING_CLOCK         1
#define TIMERS_T0_8_PRESCALER_CLOCK           2
#define TIMERS_T0_64_PRESCALER_CLOCK          3
#define TIMERS_T0_256_PRESCALER_CLOCK         4
#define TIMERS_T0_1024_PRESCALER_CLOCK        5
#define TIMERS_T0_8_FALLING_EDGE_CLOCK        6
#define TIMERS_T0_8_RISING_EDGE_CLOCK         7

#define TIMERS_T0_FAST_PWM_COMPARE_OUT_NORMAL_MODE           0
#define TIMERS_T0_FAST_PWM_COMPARE_OUT_NON_INVERTING_MODE    1
#define TIMERS_T0_FAST_PWM_COMPARE_OUT_INVERTING_MODE        2

#define TIMERS_T0_NON_PWM_COMPARE_OUT_NORMAL_MODE           0
#define TIMERS_T0_NON_PWM_COMPARE_OUT_TOGGLE_MODE           1
#define TIMERS_T0_NON_PWM_COMPARE_OUT_CLR_MODE              2
#define TIMERS_T0_NON_PWM_COMPARE_OUT_SET_MODE              3


void TIMER0_voidInit();
u8 TIMERS_u8Timer0SetCallBack(void (*Copy_pf)(void));

u8 TIMERS_u8Timer0CTCSetCallBack(void (*Copy_pf)(void));

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value);


void TIMER1_voidInit();
void TIMER1_voidSetCompareMatchValueA(u16 Copy_u8OCR1AValue);
void TIMER1_voidSetTimerValue(u16 Copy_u16Value);
u16 TIMER1_u16ReadTimerValue();

#endif //TIMERS_INTERFACE_H
