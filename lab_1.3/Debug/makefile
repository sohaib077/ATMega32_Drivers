################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
lab_1.3.lss \

FLASH_IMAGE += \
lab_1.3.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: lab_1.3.elf secondary-outputs

# Tool invocations
lab_1.3.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,lab_1.3.map -mmcu=atmega32 -o "lab_1.3.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lab_1.3.lss: lab_1.3.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S lab_1.3.elf  >"lab_1.3.lss"
	@echo 'Finished building: $@'
	@echo ' '

lab_1.3.hex: lab_1.3.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex lab_1.3.elf  "lab_1.3.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: lab_1.3.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 lab_1.3.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) lab_1.3.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
