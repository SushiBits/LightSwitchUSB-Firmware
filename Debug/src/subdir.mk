################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/board.c \
../src/main.c 

OBJS += \
./src/board.o \
./src/main.o 

C_DEPS += \
./src/board.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wall  -g3 -DSTM32F042x6 -DHSE_VALUE=8000000 -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/system/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/platform/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/cmsis/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


