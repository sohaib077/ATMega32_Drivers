//
// Created by sohai on 2/13/2024.
//

/****************************************************/
/**************** Name : Sohaib     *****************/
/**************** Date : 2/13/2024 *****************/
/**************** SWC  : USART     *****************/
/**************** Version : 1.0     *****************/
/****************************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


/*  USART Mode Select */
#define ASYNCHRONOUS   0
#define SYNCHRONOUS    1

/*  Parity Mode */
#define DISABLED      0
#define EVEN_PARITY   2
#define ODD_PARITY    3

/*  Stop Bit Select */
#define STOP_BIT_1   0
#define STOP_BIT_2   1

/*  Character Size */
#define DATA_SIZE_5_BIT   0
#define DATA_SIZE_6_BIT   1
#define DATA_SIZE_7_BIT   2
#define DATA_SIZE_8_BIT   3
#define DATA_SIZE_9_BIT   7

/*  Clock Polarity */
#define XCK_RISING_TXD    0
#define XCK_FALLING_TXD   1

void USART_voidInit(void);

u8 USART_u8ReceiveData(u8 *Copy_u8ReceivedData);

u8 USART_u8SendData(u8 Copy_u8Data);

u8 USART_u8ReceiveDataAsync(u8 *Copy_u8ReceivedData, void(*Copy_pfNotification)(void));

u8 USART_u8ReceiveStringAsync(u8 *Copy_u8ReceivedData, u8 Copy_u8StringLength,
                              void (*Copy_pfNotification)(void));

u8 USART_u8SendDataAsync(u8 Copy_u8Data);

u8 USART_u8SendStringAsync(u8 *Copy_u8StringData ,  void (*Copy_pfNotification)(void));

#endif //USART_INTERFACE_H
