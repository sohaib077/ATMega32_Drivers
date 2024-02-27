//
// Created by sohai on 2/21/2024.
//

/****************************************************/
/**************** Name : Sohaib     *****************/
/**************** Date : 2/21/2024 *****************/
/**************** SWC  : TWI     *****************/
/**************** Version : 1.0     *****************/
/****************************************************/

#ifndef TWI_CONFIG_H
#define TWI_CONFIG_H

#define F_CPU 8000000UL

#define TWI_PRESCALLER  PRESCALLER_BY_1


/*Set SCL frequency to 400kHz, with 8Mhz system frequency*/
#define SCL_Clock  400000UL

#endif //TWI_CONFIG_H