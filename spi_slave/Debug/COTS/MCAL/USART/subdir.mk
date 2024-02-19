################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../COTS/MCAL/USART/USART_program\ .c 

OBJS += \
./COTS/MCAL/USART/USART_program\ .o 

C_DEPS += \
./COTS/MCAL/USART/USART_program\ .d 


# Each subdirectory must supply rules for building sources it contributes
COTS/MCAL/USART/USART_program\ .o: ../COTS/MCAL/USART/USART_program\ .c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"COTS/MCAL/USART/USART_program .d" -MT"COTS/MCAL/USART/USART_program\ .d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


