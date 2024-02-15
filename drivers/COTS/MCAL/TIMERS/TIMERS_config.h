//
// Created by sohai on 10/14/2023.
//

/****************************************************/
/**************** Name : Sohaib     *****************/
/**************** Date : 10/14/2023 *****************/
/**************** SWC  : TIMERS     *****************/
/**************** Version : 1.0     *****************/
/****************************************************/

#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H

#define TIMERS_T0_MODE  TIMERS_T0_FAST_PWM_MODE

#define TIMERS_T0_CLOCK  TIMERS_T0_8_PRESCALER_CLOCK

#define TIMERS_T0_PRELOAD_VALUE               192
#define TIMERS_T0_OVERFLOW_COUNT              10000
#define TIMERS_T0_CTC_COUNT                   99
#define TIMERS_T0_COMPARE_MATCH_VALUE         64

#define TIMERS_T0_NON_PWM_COMPARE_OUT_MODE    TIMERS_T0_NON_PWM_COMPARE_OUT_NORMAL_MODE

#define TIMERS_T0_FAST_PWM_COMPARE_OUT_MODE    TIMERS_T0_FAST_PWM_COMPARE_OUT_NON_INVERTING_MODE


/******************* TIMER 1 *******************/

#define TIMERS_T1_CLOCK  TIMERS_T0_8_PRESCALER_CLOCK


#endif //TIMERS_CONFIG_H
