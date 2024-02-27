//
// Created by sohai on 10/14/2023.
//

/****************************************************/
/**************** Name : Sohaib     *****************/
/**************** Date : 10/14/2023 *****************/
/**************** SWC  : TIMERS     *****************/
/**************** Version : 1.0     *****************/
/****************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMERS_config.h"
#include "TIMERS_private.h"
#include "TIMERS_interface.h"
#include "TIMERS_register.h"

static void (*TIMERS_pfTimer0Overflow)(void) = NULL;

static void (*TIMERS_pfTimer0CTC)(void) = NULL;


/***********************	T I M E R 0		*****************************/

void TIMER0_voidInit() {
    /* Mode */
#if TIMERS_T0_MODE == TIMERS_T0_NORMAL_MODE
    CLR_BIT(TCCR0, TCCR0_WGM00);
    CLR_BIT(TCCR0, TCCR0_WGM01);

    /* Preload value */
    TCNT0 = TIMERS_T0_PRELOAD_VALUE;

    /* Enable overflow Interrupt */
    SET_BIT(TIMSK, TIMSK_TOIE0);


#elif TIMERS_T0_MODE == TIMERS_T0_CTC_MODE
    CLR_BIT(TCCR0, TCCR0_WGM00);
    SET_BIT(TCCR0, TCCR0_WGM01);

    /* Set compare match value */
    OCR0 = TIMERS_T0_CTC_COUNT;

    /* Enable overflow Interrupt */
    SET_BIT(TIMSK, TIMSK_OCIE0);

#elif TIMERS_T0_MODE == TIMERS_T0_PHASE_CORRECT_PWM_MODE
    SET_BIT(TCCR0 , TCCR0_WGM00);
    CLR_BIT(TCCR0 , TCCR0_WGM01);

    /*  Compare Output Mode */
    #if TIMERS_T0_PHASE_CORRECT_PWM_COMPARE_OUT_MODE ==  TIMERS_T0_PHASE_CORRECT_PWM_COMPARE_OUT_NORMAL_MODE
                    CLR_BIT(TCCR0 , TCCR0_COM00);
                    CLR_BIT(TCCR0 , TCCR0_COM01);

    #elif TIMERS_T0_PHASE_CORRECT_PWM_COMPARE_OUT_MODE ==  TIMERS_T0_PHASE_CORRECT_PWM_COMPARE_OUT_INVERTING_MODE
                    CLR_BIT(TCCR0 , TCCR0_COM00);
                    SET_BIT(TCCR0 , TCCR0_COM01);

    #elif TIMERS_T0_PHASE_CORRECT_PWM_COMPARE_OUT_MODE ==  TIMERS_T0_PHASE_CORRECT_PWM_COMPARE_OUT_NON_INVERTING_MODE
                    SET_BIT(TCCR0 , TCCR0_COM00);
                    SET_BIT(TCCR0 , TCCR0_COM01);

    #else
    #error " Wrong TIMERS_T0_PHASE_CORRECT_PWM_MODE Compare Output Mode "
    #endif

    /* Set compare match value */
    OCR0 = TIMERS_T0_COMPARE_MATCH_VALUE;

    /* Enable overflow Interrupt */
    SET_BIT(TIMSK, TIMSK_TOIE0);


#elif TIMERS_T0_MODE == TIMERS_T0_FAST_PWM_MODE
    SET_BIT(TCCR0, TCCR0_WGM00);
    SET_BIT(TCCR0, TCCR0_WGM01);


    /*  Compare Output Mode */
#if TIMERS_T0_FAST_PWM_COMPARE_OUT_MODE == TIMERS_T0_PHASE_CORRECT_PWM_COMPARE_OUT_NORMAL_MODE
    CLR_BIT(TCCR0 , TCCR0_COM00);
    CLR_BIT(TCCR0 , TCCR0_COM01);

#elif TIMERS_T0_FAST_PWM_COMPARE_OUT_MODE == TIMERS_T0_FAST_PWM_COMPARE_OUT_NON_INVERTING_MODE
    CLR_BIT(TCCR0, TCCR0_COM00);
    SET_BIT(TCCR0, TCCR0_COM01);

#elif TIMERS_T0_FAST_PWM_COMPARE_OUT_MODE == TIMERS_T0_FAST_PWM_COMPARE_OUT_INVERTING_MODE
    SET_BIT(TCCR0 , TCCR0_COM00);
    SET_BIT(TCCR0 , TCCR0_COM01);

#else
#error " Wrong TIMERS_T0_FAST_PWM_MODE Compare Output Mode "
#endif

    /* Set compare match value */
    OCR0 = TIMERS_T0_COMPARE_MATCH_VALUE;

    /* Enable overflow Interrupt */
    SET_BIT(TIMSK, TIMSK_TOIE0);

#else
#error " Wrong TIMERS_T0_MODE "
#endif


/* Select hardware action on OC0 pin when compare match in non PWM mode */
#if TIMERS_T0_MODE == TIMERS_T0_NORMAL_MODE || TIMERS_T0_MODE == TIMERS_T0_CTC_MODE
    #if TIMERS_T0_NON_PWM_COMPARE_OUT_MODE == TIMERS_T0_NON_PWM_COMPARE_OUT_NORMAL_MODE
        CLR_BIT(TCCR0, TCCR0_COM00);
        CLR_BIT(TCCR0, TCCR0_COM01);

    #elif TIMERS_T0_NON_PWM_COMPARE_OUT_MODE == TIMERS_T0_NON_PWM_COMPARE_OUT_TOGGLE_MODE
        SET_BIT(TCCR0, TCCR0_COM00);
        CLR_BIT(TCCR0, TCCR0_COM01);

    #elif TIMERS_T0_NON_PWM_COMPARE_OUT_MODE == TIMERS_T0_NON_PWM_COMPARE_OUT_CLR_MODE
        CLR_BIT(TCCR0, TCCR0_COM00);
        SET_BIT(TCCR0, TCCR0_COM01);

    #elif TIMERS_T0_NON_PWM_COMPARE_OUT_MODE == TIMERS_T0_NON_PWM_COMPARE_OUT_SET_MODE
        SET_BIT(TCCR0, TCCR0_COM00);
        SET_BIT(TCCR0, TCCR0_COM01);
    #else
    #error " Wrong TIMERS_T0_NON_PWM_MODE Compare Output Mode"
    #endif
#endif

    /* Prescaler Clock */
    TCCR0 &= 0b11111000;
    TCCR0 |= TIMERS_T0_CLOCK;
}


void TIMER0_voidSetCompareMatchValue(u8 Copy_u8OCR0Value) {
    OCR0 = Copy_u8OCR0Value;
}

void TIMER0_voidSetPreloadValue(u8 Copy_u8PreloadValue) {
    TCNT0 = Copy_u8PreloadValue;
}

u8 TIMER0_u8GetTimerCounterValue() {
    return TCNT0;
}

u8 TIMER0_voidChangeOutCompareMatchInterruptState(INTERRUPT_STATE enum_CopyState) {
    if (enum_CopyState == DISABLE)     CLR_BIT(TIMSK, TIMSK_OCIE0);
    else if (enum_CopyState == ENABLE) SET_BIT(TIMSK, TIMSK_OCIE0);
    else return NOT_OK;
    return OK;
}

u8 TIMER0_voidChangeOverFlowInterruptState(INTERRUPT_STATE enum_CopyState) {
    if (enum_CopyState == DISABLE)     CLR_BIT(TIMSK, TIMSK_TOIE0);
    else if (enum_CopyState == ENABLE) SET_BIT(TIMSK, TIMSK_TOIE0);
    else return NOT_OK;
    return OK;
}

u8 TIMER0_u8SetCallBack(void (*Copy_pf)(void)) {
    if (Copy_pf == NULL) return NULL_POINTER;
    TIMERS_pfTimer0Overflow = Copy_pf;
    return OK;
}

u8 TIMER0_u8CTCSetCallBack(void (*Copy_pf)(void)) {
    if (Copy_pf == NULL) return NULL_POINTER;
    TIMERS_pfTimer0CTC = Copy_pf;
    return OK;
}

/***********************	T I M E R 1		*****************************/

void TIMER1_voidInit() {

    /* SET MODE */
    CLR_BIT(TCCR1A, TCCR1A_WGM10);
    CLR_BIT(TCCR1A, TCCR1A_WGM11);
    CLR_BIT(TCCR1B, TCCR1B_WGM12);
    CLR_BIT(TCCR1B, TCCR1B_WGM13);

    /* SET HARDWARE ACTION ON OC1A PIN */
//    CLR_BIT(TCCR1A,TCCR1A_COM1A0);
//    SET_BIT(TCCR1A,TCCR1A_COM1A1);

    /* SET TOP VALUE IN ICR1 */
//    ICR1 = 19999;

    /* SET SERVO MOTOR ANGLE */
//    OCR1A = 999;

    /* SET PRESCALER CLOCK */
//    TCCR1B &= 0b11111000;
//    TCCR1B |= TIMERS_T1_CLOCK;
    CLR_BIT(TCCR1B, TCCR1B_CS10);
    SET_BIT(TCCR1B, TCCR1B_CS11);
    CLR_BIT(TCCR1B, TCCR1B_CS12);
}

void TIMER1_voidSetCompareMatchValueA(u16 Copy_u8OCR1AValue) {
//    OCR1A = ((Copy_u8OCR1AValue ) / 0.180) + 999;
    OCR1A = Copy_u8OCR1AValue;
}

void TIMER1_voidSetTimerValue(u16 Copy_u16Value) {
    TCNT1 = Copy_u16Value;

}

u16 TIMER1_u16ReadTimerValue() {
    return TCNT1;
}

void __vector_11() __attribute__((signal));

void __vector_11() {
    static u16 Local_u16OverflowCounter = 0;
    Local_u16OverflowCounter++;
    if (Local_u16OverflowCounter == TIMERS_T0_OVERFLOW_COUNT) {
        TCNT0 = TIMERS_T0_PRELOAD_VALUE;
        Local_u16OverflowCounter = 0;
        if (TIMERS_pfTimer0Overflow != NULL) {
            TIMERS_pfTimer0Overflow();
        }
    }
}

void __vector_10() __attribute__((signal));

void __vector_10() {
    static u16 Local_u16CTCCounter = 0;
    Local_u16CTCCounter++;
    if (Local_u16CTCCounter == TIMERS_T0_OVERFLOW_COUNT) {
        //        OCR0 = TIMERS_T0_CTC_COUNT;
        Local_u16CTCCounter = 0;
        if (TIMERS_pfTimer0CTC != NULL) {
            TIMERS_pfTimer0CTC();
        }
    }
}
