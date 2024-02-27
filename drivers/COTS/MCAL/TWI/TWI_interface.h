//
// Created by sohai on 2/21/2024.
//

/****************************************************/
/**************** Name : Sohaib     *****************/
/**************** Date : 2/21/2024 *****************/
/**************** SWC  : TWI     *****************/
/**************** Version : 1.0     *****************/
/****************************************************/

#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H


/* Prescalers */
#define PRESCALLER_BY_1    1
#define PRESCALLER_BY_4    4
#define PRESCALLER_BY_16   16
#define PRESCALLER_BY_64   64


/* Error Status fot TWI */
typedef enum
{
    NoError,
    StartConditionErr,
    RepeatedStartError,
    SlaveAddressWithWriteErr,
    SlaveAddressWithReadErr,
    MasterWriteByteErr,
    MasterReadByteErr,
    SlaveWriteByteErr,
    SlaveReadByteErr,

}TWI_ErrStatus;

/*Set master address to 0 if master will not be addressed*/
void TWI_voidInitMaster(u8 Copy_u8Address);

void TWI_voidInitSlave(u8 Copy_u8Address);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStart(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(u8* Copy_pu8DataByte);

TWI_ErrStatus TWI_SlaveWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_SlaveReadDataByte(u8* Copy_pu8DataByte);


void TWI_SendStopCondition(void);


#endif //TWI_INTERFACE_H