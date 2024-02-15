################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lcd_labs/bouncing_special_string.c \
../lcd_labs/shifting_special_string.c \
../lcd_labs/sin_wave.c 

OBJS += \
./lcd_labs/bouncing_special_string.o \
./lcd_labs/shifting_special_string.o \
./lcd_labs/sin_wave.o 

C_DEPS += \
./lcd_labs/bouncing_special_string.d \
./lcd_labs/shifting_special_string.d \
./lcd_labs/sin_wave.d 


# Each subdirectory must supply rules for building sources it contributes
lcd_labs/%.o: ../lcd_labs/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


