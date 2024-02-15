################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../keypad_labs/calculator.c \
../keypad_labs/keybad.c 

OBJS += \
./keypad_labs/calculator.o \
./keypad_labs/keybad.o 

C_DEPS += \
./keypad_labs/calculator.d \
./keypad_labs/keybad.d 


# Each subdirectory must supply rules for building sources it contributes
keypad_labs/%.o: ../keypad_labs/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


