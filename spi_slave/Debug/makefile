################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include COTS/MCAL/USART/subdir.mk
-include COTS/MCAL/TIMERS/subdir.mk
-include COTS/MCAL/SPI/subdir.mk
-include COTS/MCAL/PORT/subdir.mk
-include COTS/MCAL/GIE/subdir.mk
-include COTS/MCAL/EXTI/subdir.mk
-include COTS/MCAL/DIO/subdir.mk
-include COTS/MCAL/ADC/subdir.mk
-include COTS/HAL/STEPPER/subdir.mk
-include COTS/HAL/LCD/subdir.mk
-include COTS/HAL/KeyPad/subdir.mk
-include COTS/APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
spi_slave.lss \

FLASH_IMAGE += \
spi_slave.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: spi_slave.elf secondary-outputs

# Tool invocations
spi_slave.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,spi_slave.map -mmcu=atmega32 -o "spi_slave.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

spi_slave.lss: spi_slave.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S spi_slave.elf  >"spi_slave.lss"
	@echo 'Finished building: $@'
	@echo ' '

spi_slave.hex: spi_slave.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex spi_slave.elf  "spi_slave.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: spi_slave.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 spi_slave.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) spi_slave.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
