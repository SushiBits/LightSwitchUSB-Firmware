################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/gpio.c \
../system/src/sbrk.c \
../system/src/time.c 

OBJS += \
./system/src/gpio.o \
./system/src/sbrk.o \
./system/src/time.o 

C_DEPS += \
./system/src/gpio.d \
./system/src/sbrk.d \
./system/src/time.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/%.o: ../system/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wall  -g3 -DSTM32F042x6 -DHSE_VALUE=8000000 -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/system/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/platform/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/cmsis/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


