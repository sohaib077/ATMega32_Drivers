//
// Created by sohai on 2/17/2024.
//

/****************************************************/
/**************** Name : Sohaib     *****************/
/**************** Date : 2/17/2024 *****************/
/**************** SWC  : SPI     *****************/
/**************** Version : 1.0     *****************/
/****************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/* SPI_DATA_ORDER */
#define MSB_TRANSMITTED_FIRST       0
#define LSB_TRANSMITTED_FIRST       1

/* SPI_CLK_POLARITY */
#define POLARITY_RISING_LEADING     0
#define POLARITY_FALLING_LEADING    1

/* SPI_CLK_PHASE */
#define PHASE_SAMPLE_LEADING        0
#define PHASE_SETUP_LEADING         1

/* SPI_CLK_RATE */
#define FREQUENCY_DIVIDED_BY_2      0
#define FREQUENCY_DIVIDED_BY_4      1
#define FREQUENCY_DIVIDED_BY_8      2
#define FREQUENCY_DIVIDED_BY_16     3
#define FREQUENCY_DIVIDED_BY_32     4
#define FREQUENCY_DIVIDED_BY_64     5
#define FREQUENCY_DIVIDED_BY_128    6


void SPI_VoidMasterInit(void);

void SPI_VoidSlaveInit(void);

u8 SPI_u8TransceiveSync(u8 Copy_u8Data, u8 *Copy_pu8ReceivedData);

/* Don't forget to enable Global Interrupt first */
u8 SPI_u8TransceiveAsync(u8 Copy_u8Data, u8 *Copy_pu8ReceivedData, void(*Copy_pfNotification)(void));

/* Don't forget to enable Global Interrupt first */
u8 SPI_u8TransceiveStringAsync(u8 *Copy_u8Data, u8 *Copy_pu8ReceivedData, u8 Copy_u8StringLength,
                               void(*Copy_pfNotification)(void));

#endif //SPI_INTERFACE_H
