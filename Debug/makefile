################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include system/src/subdir.mk
-include src/subdir.mk
-include platform/src/subdir.mk
-include contrib/libusb-stm32/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
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
SECONDARY_FLASH += \
LightSwitchUSB.bin \

SECONDARY_SIZE += \
LightSwitchUSB.siz \


# All Target
all: LightSwitchUSB.elf secondary-outputs

# Tool invocations
LightSwitchUSB.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM Cross C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wall  -g3 -T "/Users/technix/Developer/Eclipse/default/LightSwitchUSB/platform/src/stm32f04xx4.ld" -T "/Users/technix/Developer/Eclipse/default/LightSwitchUSB/platform/src/cortex-m0.ld" -Xlinker --gc-sections -L"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/cmsis/lib" -Wl,-Map,"LightSwitchUSB.map" --specs=nano.specs -o "LightSwitchUSB.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LightSwitchUSB.bin: LightSwitchUSB.elf
	@echo 'Invoking: GNU ARM Cross Create Flash Image'
	arm-none-eabi-objcopy -O binary "LightSwitchUSB.elf"  "LightSwitchUSB.bin"
	@echo 'Finished building: $@'
	@echo ' '

LightSwitchUSB.siz: LightSwitchUSB.elf
	@echo 'Invoking: GNU ARM Cross Print Size'
	arm-none-eabi-size --format=berkeley "LightSwitchUSB.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) LightSwitchUSB.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
