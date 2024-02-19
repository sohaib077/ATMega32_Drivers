//
// Created by sohai on 2/17/2024.
//

/****************************************************/
/**************** Name : Sohaib     *****************/
/**************** Date : 2/17/2024 *****************/
/**************** SWC  : SPI     *****************/
/**************** Version : 1.0     *****************/
/****************************************************/

#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H

#define SPCR   *((volatile u8 *) 0x2D)  /* SPI Control Register */
#define SPCR_SPIE       7               /* SPI Enable */
#define SPCR_SPE        6               /* SPI Interrupt Enable */
#define SPCR_DORD       5               /* Data Order */
#define SPCR_MSTR       4               /* Master/Slave Select */
#define SPCR_CPOL       3               /* Clock Polarity */
#define SPCR_CPHA       2               /* Clock Phase */
#define SPCR_SPR1       1               /* SPI Clock Rate Select 1 */
#define SPCR_SPR0       0               /* SPI Clock Rate Select 0 */

#define SPSR   *((volatile u8 *) 0x2E)  /* SPI Status Register */
#define SPSR_SPIF       7               /* SPI Interrupt Flag */
#define SPSR_WCOL       6               /* Write Collision Flag */
#define SPSR_SPI2X      0               /* Double SPI Speed Bit */

#define SPDR   *((volatile u8 *) 0x2F)  /* SPI Data Register */

#endif //SPI_REGISTER_H