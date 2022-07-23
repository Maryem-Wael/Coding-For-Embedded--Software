################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/DIO.c \
../Drivers/src/DIO_Cfg.c 

OBJS += \
./Drivers/src/DIO.o \
./Drivers/src/DIO_Cfg.o 

C_DEPS += \
./Drivers/src/DIO.d \
./Drivers/src/DIO_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o: ../Drivers/src/%.c Drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -c -I"C:/Users/mohanned/Desktop/42_proxy/inc" -I"C:/Users/mohanned/Desktop/42_proxy/CMSIS/device" -I"C:/Users/mohanned/Desktop/42_proxy/CMSIS/core" -I"C:/Users/mohanned/Desktop/42_proxy/SDrivers/inc" -I"C:/Users/mohanned/Desktop/42_proxy/Drivers/inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

