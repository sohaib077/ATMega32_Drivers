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

enum INTERRUPT_STATE {
    ENABLE, DISABLE
};

/* Timer Mode */
#define TIMERS_T0_NORMAL_MODE                   0
#define TIMERS_T0_PHASE_CORRECT_PWM_MODE        1
#define TIMERS_T0_CTC_MODE                      2
#define TIMERS_T0_FAST_PWM_MODE                 3

/* Clock Select */
#define TIMERS_T0_NO_CLOCK                    0
#define TIMERS_T0_NO_PRESCALING_CLOCK         1
#define TIMERS_T0_8_PRESCALER_CLOCK           2
#define TIMERS_T0_64_PRESCALER_CLOCK          3
#define TIMERS_T0_256_PRESCALER_CLOCK         4
#define TIMERS_T0_1024_PRESCALER_CLOCK        5
#define TIMERS_T0_8_FALLING_EDGE_CLOCK        6
#define TIMERS_T0_8_RISING_EDGE_CLOCK         7

/* Compare Output Mode, non-PWM Mode */
#define TIMERS_T0_NON_PWM_COMPARE_OUT_NORMAL_MODE           0
#define TIMERS_T0_NON_PWM_COMPARE_OUT_TOGGLE_MODE           1
#define TIMERS_T0_NON_PWM_COMPARE_OUT_CLR_MODE              2
#define TIMERS_T0_NON_PWM_COMPARE_OUT_SET_MODE              3

/* Compare Output Mode, Fast PWM Mode */
#define TIMERS_T0_FAST_PWM_COMPARE_OUT_NORMAL_MODE           0
#define TIMERS_T0_FAST_PWM_COMPARE_OUT_NON_INVERTING_MODE    2  /* Clear OC0 on compare match, set OC0 at TOP */
#define TIMERS_T0_FAST_PWM_COMPARE_OUT_INVERTING_MODE        3  /* Set OC0 on compare match, clear OC0 at TOP */

/* Compare Output Mode, Phase Correct PWM Mode */
#define TIMERS_T0_PHASE_CORRECT_PWM_COMPARE_OUT_NORMAL_MODE           0
#define TIMERS_T0_PHASE_CORRECT_PWM_COMPARE_OUT_INVERTING_MODE        2  /* Clear OC0 on compare match when up-counting */
#define TIMERS_T0_PHASE_CORRECT_PWM_COMPARE_OUT_NON_INVERTING_MODE    3  /* Set OC0 on compare match when up-counting */


void TIMER0_voidInit();

void TIMER0_voidSetCompareMatchValue(u8 Copy_u8OCR0Value);

void TIMER0_voidSetPreloadValue(u8 Copy_u8PreloadValue);

u8 TIMER0_u8GetTimerCounterValue();

u8 TIMER0_voidChangeOutCompareMatchInterruptState(INTERRUPT_STATE enum_CopyState);

u8 TIMER0_voidChangeOverFlowInterruptState(INTERRUPT_STATE enum_CopyState);

u8 TIMER0_u8SetCallBack(void (*Copy_pf)(void));

u8 TIMER0_u8CTCSetCallBack(void (*Copy_pf)(void));


/***********************	T I M E R 1		*****************************/


void TIMER1_voidInit();

void TIMER1_voidSetCompareMatchValueA(u16 Copy_u8OCR1AValue);

void TIMER1_voidSetTimerValue(u16 Copy_u16Value);

u16 TIMER1_u16ReadTimerValue();

#endif //TIMERS_INTERFACE_H
