################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include motor_labs/subdir.mk
-include lcd_labs/subdir.mk
-include keypad_labs/subdir.mk
-include USART/subdir.mk
-include TIMERS/subdir.mk
-include SPI/subdir.mk
-include Relay/subdir.mk
-include Full_Calculator/subdir.mk
-include EXTI/subdir.mk
-include ADC/subdir.mk
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
LABS.lss \

FLASH_IMAGE += \
LABS.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: LABS.elf secondary-outputs

# Tool invocations
LABS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LABS.map -mmcu=atmega32 -o "LABS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LABS.lss: LABS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LABS.elf  >"LABS.lss"
	@echo 'Finished building: $@'
	@echo ' '

LABS.hex: LABS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LABS.elf  "LABS.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LABS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LABS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LABS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
