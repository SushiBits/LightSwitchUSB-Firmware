################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../platform/src/sbrk.c \
../platform/src/stm32f0xx_it.c \
../platform/src/system_stm32f0xx.c 

OBJS += \
./platform/src/sbrk.o \
./platform/src/stm32f0xx_it.o \
./platform/src/system_stm32f0xx.o 

C_DEPS += \
./platform/src/sbrk.d \
./platform/src/stm32f0xx_it.d \
./platform/src/system_stm32f0xx.d 


# Each subdirectory must supply rules for building sources it contributes
platform/src/%.o: ../platform/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wall  -g3 -DSTM32F042x6 -DUSB_PMASIZE=0x400 -DHSE_VALUE=8000000 -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/contrib/libusb-stm32/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/system/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/platform/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/cmsis/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


