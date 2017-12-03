################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../contrib/libusb-stm32/src/usb_32v0.c \
../contrib/libusb-stm32/src/usb_32v1.c \
../contrib/libusb-stm32/src/usb_32v2.c \
../contrib/libusb-stm32/src/usb_32v3.c \
../contrib/libusb-stm32/src/usbd_core.c 

S_UPPER_SRCS += \
../contrib/libusb-stm32/src/usb_32v0A.S \
../contrib/libusb-stm32/src/usb_32v1A.S 

OBJS += \
./contrib/libusb-stm32/src/usb_32v0.o \
./contrib/libusb-stm32/src/usb_32v0A.o \
./contrib/libusb-stm32/src/usb_32v1.o \
./contrib/libusb-stm32/src/usb_32v1A.o \
./contrib/libusb-stm32/src/usb_32v2.o \
./contrib/libusb-stm32/src/usb_32v3.o \
./contrib/libusb-stm32/src/usbd_core.o 

S_UPPER_DEPS += \
./contrib/libusb-stm32/src/usb_32v0A.d \
./contrib/libusb-stm32/src/usb_32v1A.d 

C_DEPS += \
./contrib/libusb-stm32/src/usb_32v0.d \
./contrib/libusb-stm32/src/usb_32v1.d \
./contrib/libusb-stm32/src/usb_32v2.d \
./contrib/libusb-stm32/src/usb_32v3.d \
./contrib/libusb-stm32/src/usbd_core.d 


# Each subdirectory must supply rules for building sources it contributes
contrib/libusb-stm32/src/%.o: ../contrib/libusb-stm32/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wall  -g3 -DSTM32F042x6 -DUSB_PMASIZE=0x400 -DHSE_VALUE=8000000 -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/contrib/libusb-stm32/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/system/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/platform/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/cmsis/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

contrib/libusb-stm32/src/%.o: ../contrib/libusb-stm32/src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wall  -g3 -x assembler-with-cpp -DSTM32F042x6 -DUSB_PMASIZE=0x400 -DHSE_VALUE=8000000 -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/contrib/libusb-stm32/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/system/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/platform/include" -I"/Users/technix/Developer/Eclipse/default/LightSwitchUSB/cmsis/include" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


