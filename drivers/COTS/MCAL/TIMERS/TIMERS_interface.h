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

/* All Timers Clock Select */
#define TIMERS_NO_CLOCK                    0
#define TIMERS_NO_PRESCALING_CLOCK         1
#define TIMERS_8_PRESCALER_CLOCK           2
#define TIMERS_64_PRESCALER_CLOCK          3
#define TIMERS_256_PRESCALER_CLOCK         4
#define TIMERS_1024_PRESCALER_CLOCK        5
#define TIMERS_8_FALLING_EDGE_CLOCK        6
#define TIMERS_8_RISING_EDGE_CLOCK         7


/************************************************************************/
/***********************	T I M E R 0		*****************************/
/************************************************************************/

/* Timer Mode */
#define TIMER0_NORMAL_MODE                   0
#define TIMER0_PHASE_CORRECT_PWM_MODE        1
#define TIMER0_CTC_MODE                      2
#define TIMER0_FAST_PWM_MODE                 3

/* Compare Output Mode, non-PWM Mode */
#define TIMER0_NON_PWM_COMPARE_OUT_NORMAL_MODE           0
#define TIMER0_NON_PWM_COMPARE_OUT_TOGGLE_MODE           1
#define TIMER0_NON_PWM_COMPARE_OUT_CLR_MODE              2
#define TIMER0_NON_PWM_COMPARE_OUT_SET_MODE              3

/* Compare Output Mode, Fast PWM Mode */
#define TIMER0_FAST_PWM_COMPARE_OUT_NORMAL_MODE           0
#define TIMER0_FAST_PWM_COMPARE_OUT_NON_INVERTING_MODE    2  /* Clear OC0 on compare match, set OC0 at TOP */
#define TIMER0_FAST_PWM_COMPARE_OUT_INVERTING_MODE        3  /* Set OC0 on compare match, clear OC0 at TOP */

/* Compare Output Mode, Phase Correct PWM Mode */
#define TIMER0_PHASE_CORRECT_PWM_COMPARE_OUT_NORMAL_MODE           0
#define TIMER0_PHASE_CORRECT_PWM_COMPARE_OUT_INVERTING_MODE        2  /* Clear OC0 on compare match when up-counting */
#define TIMER0_PHASE_CORRECT_PWM_COMPARE_OUT_NON_INVERTING_MODE    3  /* Set OC0 on compare match when up-counting */


void TIMER0_voidInit();

void TIMER0_voidSetCompareMatch(u8 Copy_u8OCR0Value);

void TIMER0_voidSetPreload(u8 Copy_u8PreloadValue);

u8 TIMER0_u8ReadTimer();

u8 TIMER0_voidChangeOutCompareMatchInterruptState(INTERRUPT_STATE enum_CopyState);

u8 TIMER0_voidChangeOverFlowInterruptState(INTERRUPT_STATE enum_CopyState);

u8 TIMER0_u8SetCallBack(void (*Copy_pf)(void));

u8 TIMER0_u8CTCSetCallBack(void (*Copy_pf)(void));


/************************************************************************/
/***********************	T I M E R 1		*****************************/
/************************************************************************/

/* TIMER1 MODE */
#define TIMER1_NORMAL_MODE                                 0
#define TIMER1_PWM_8_BIT_MODE                              1
#define TIMER1_PWM_9_BIT_MODE                              2
#define TIMER1_PWM_10_BIT_MODE                             3
#define TIMER1_CTC_OCR1A_MODE                              4
#define TIMER1_FAST_PWM_8_BIT_MODE                         5
#define TIMER1_FAST_PWM_9_BIT_MODE                         6
#define TIMER1_FAST_PWM_10_BIT_MODE                        7
#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE        8
#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE       9
#define TIMER1_PWM_PHASE_CORRECT_ICR1_MODE                10
#define TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE               11
#define TIMER1_CTC_ICR1_MODE                              12
#define TIMER1_FAST_PWM_ICR1_MODE                         14
#define TIMER1_FAST_PWM_OCR1A_MODE                        15

/* Compare Output Mode, non-PWM Mode */
#define TIMER1_NON_PWM_COMPARE_OUT_NORMAL_MODE           0
#define TIMER1_NON_PWM_COMPARE_OUT_TOGGLE_MODE           1
#define TIMER1_NON_PWM_COMPARE_OUT_CLR_MODE              2
#define TIMER1_NON_PWM_COMPARE_OUT_SET_MODE              3

/* Compare Output Mode, FAST PWM Mode */
#define TIMER1_FAST_PWM_COMPARE_OUT_NORMAL_MODE           0
#define TIMER1_FAST_PWM_COMPARE_OUT_TOGGLE_MODE           1
#define TIMER1_FAST_PWM_COMPARE_OUT_NON_INVERTING_MODE    2  /* Clear OC1A/B on compare match, set OC1A/B at TOP */
#define TIMER1_FAST_PWM_COMPARE_OUT_INVERTING_MODE        3  /* Set OC1A/B on compare match, clear OC1A/B at TOP */

/* Compare Output Mode, Phase Correct and Phase and Frequency Correct Mode */
#define TIMER1_PHASE_FREQ_CORRECT_PWM_COMPARE_OUT_NORMAL_MODE           0
#define TIMER1_PHASE_FREQ_CORRECT_PWM_COMPARE_OUT_TOGGLE_MODE           1
#define TIMER1_PHASE_FREQ_CORRECT_PWM_COMPARE_OUT_INVERTING_MODE        2  /* Clear OC1A/B on compare match up counting, set OC1A/B down counting */
#define TIMER1_PHASE_FREQ_CORRECT_PWM_COMPARE_OUT_NON_INVERTING_MODE    3  /* set OC1A/B on compare match up counting, Clear OC1A/B down counting */

/* ICR edget selecting */
#define TIMER1_ICR_FALLING_EDGE     0
#define TIMER1_ICR_RISING_EDGE      1


#define TIMER1_CHANNEL_A    0
#define TIMER1_CHANNEL_B    1


void TIMER1_voidInit();


void TIMER1_voidSetPreload(u8 Copy_u8PreloadValue);

u8 TIMER1_u8SetCompareMatch(u8 Copy_u8Channel, u16 Copy_u16OCR1xValue);

u8 TIMER1_u8SetICR1(u16 Copy_u16ICR1Value);

u16 TIMER1_u16ReadTimer();

u8 TIMER1_voidChangeOverFlowInterruptState(INTERRUPT_STATE enum_CopyState);

u8 TIMER1_voidChangeOutCompareMatchInterruptState(u8 Copy_u8Channel, INTERRUPT_STATE enum_CopyState);

u8 TIMER1_voidChangeICR1InterruptState(INTERRUPT_STATE enum_CopyState);


#endif //TIMERS_INTERFACE_H
