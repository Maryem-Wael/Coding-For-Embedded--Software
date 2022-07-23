################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/GPIO.c \
../Drivers/src/PollDataClient.c \
../Drivers/src/PollerTimer.c \
../Drivers/src/device.c \
../Drivers/src/poller.c 

OBJS += \
./Drivers/src/GPIO.o \
./Drivers/src/PollDataClient.o \
./Drivers/src/PollerTimer.o \
./Drivers/src/device.o \
./Drivers/src/poller.o 

C_DEPS += \
./Drivers/src/GPIO.d \
./Drivers/src/PollDataClient.d \
./Drivers/src/PollerTimer.d \
./Drivers/src/device.d \
./Drivers/src/poller.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o: ../Drivers/src/%.c Drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -c -I"D:/Smbe/Coding-for-Embedded-Software/Lab4/43_observing/inc" -I"D:/Smbe/Coding-for-Embedded-Software/Lab4/43_observing/CMSIS/device" -I"D:/Smbe/Coding-for-Embedded-Software/Lab4/43_observing/CMSIS/core" -I"D:/Smbe/Coding-for-Embedded-Software/Lab4/43_observing/Drivers/inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

