################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../motor_labs/HBridge.c \
../motor_labs/HBridgeLcd.c \
../motor_labs/controlMotorBySwitch.c 

OBJS += \
./motor_labs/HBridge.o \
./motor_labs/HBridgeLcd.o \
./motor_labs/controlMotorBySwitch.o 

C_DEPS += \
./motor_labs/HBridge.d \
./motor_labs/HBridgeLcd.d \
./motor_labs/controlMotorBySwitch.d 


# Each subdirectory must supply rules for building sources it contributes
motor_labs/%.o: ../motor_labs/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


