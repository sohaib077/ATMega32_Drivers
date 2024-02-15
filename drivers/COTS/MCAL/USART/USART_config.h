//
// Created by sohai on 2/13/2024.
//

/****************************************************/
/**************** Name : Sohaib     *****************/
/**************** Date : 2/13/2024 *****************/
/**************** SWC  : USART     *****************/
/**************** Version : 1.0     *****************/
/****************************************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#define USART_SYSTEM_FREQUENCY    8000000UL

#define USART_BAUD_RATE           9600UL

#define USART_MODE                ASYNCHRONOUS

#define USART_PARITY_MODE         DISABLED

#define USART_STOP_BITS           STOP_BIT_1

#define USART_DATA_SIZE           DATA_SIZE_8_BIT

#define USART_CLOCK_PARITY        XCK_RISING_TXD

#define USART_u32TIMEOUT	      10000UL


#endif //USART_CONFIG_H