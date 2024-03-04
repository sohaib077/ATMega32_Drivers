//
// Created by sohai on 3/4/2024.
//

/****************************************************/
/**************** Name : Sohaib     *****************/
/**************** Date : 3/4/2024 *****************/
/**************** SWC  : WDT     *****************/
/**************** Version : 1.0     *****************/
/****************************************************/

#ifndef WDT_REGISTER_H
#define WDT_REGISTER_H


#define WDTCR   *((volatile pu8)0x41)   /* Watchdog Timer Control Register */
#define WDTCR_WDTOE     4               /* Watchdog Turn-off Enable */
#define WDTCR_WDE       3               /* Watchdog Enable */

#endif //WDT_REGISTER_H