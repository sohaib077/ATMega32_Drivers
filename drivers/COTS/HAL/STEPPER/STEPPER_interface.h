//
// Created by sohai on 10/4/2023.
//

#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H

#define STEPPER_CW_DIR 0
#define STEPPER_CCW_DIR 1

void STEPPER_voidRotateClockWise();
void STEPPER_voidRotateCOUNTERClockWise();
u8 STEPPER_u8RotateByDegrees(u32 Copy_u32Degree, u8 Copy_u8Direction);
u8 STEPPER_u8RotateBySeconds(u32 Copy_u32Second, u8 Copy_u8Direction);
#endif //STEPPER_INTERFACE_H
