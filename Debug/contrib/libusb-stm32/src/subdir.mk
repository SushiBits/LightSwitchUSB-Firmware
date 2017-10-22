################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../contrib/libusb-stm32/src/usb_32v0.c \
../contrib/libusb-stm32/src/usbd_core.c 

OBJS += \
./contrib/libusb-stm32/src/usb_32v0.o \
./contrib/libusb-stm32/src/usbd_core.o 

C_DEPS += \
./contrib/libusb-stm32/src/usb_32v0.d \
./contrib/libusb-stm32/src/usbd_core.d 


# Each subdirectory must supply rules for building sources it contributes
contrib/libusb-stm32/src/%.o: ../contrib/libusb-stm32/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wall  -g3 -DSTM32F042x6 -DUSB_PMASIZE=0x400 -DHSE_VALUE=8000000 -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/contrib/libusb-stm32/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/system/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/platform/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/cmsis/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


