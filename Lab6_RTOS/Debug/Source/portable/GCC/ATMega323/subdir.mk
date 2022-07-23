################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/portable/GCC/ATMega323/port.c 

OBJS += \
./Source/portable/GCC/ATMega323/port.o 

C_DEPS += \
./Source/portable/GCC/ATMega323/port.d 


# Each subdirectory must supply rules for building sources it contributes
Source/portable/GCC/ATMega323/%.o: ../Source/portable/GCC/ATMega323/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\moham\Desktop\Embedded\WorkSpace\AVRRTOS\Source\portable\GCC\ATMega323" -I"C:\Users\moham\Desktop\Embedded\WorkSpace\AVRRTOS\Source\portable\MemMang" -I"C:\Users\moham\Desktop\Embedded\WorkSpace\AVRRTOS\Source\include" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


