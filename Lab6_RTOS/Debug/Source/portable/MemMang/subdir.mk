################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/portable/MemMang/heap_1.c 

OBJS += \
./Source/portable/MemMang/heap_1.o 

C_DEPS += \
./Source/portable/MemMang/heap_1.d 


# Each subdirectory must supply rules for building sources it contributes
Source/portable/MemMang/%.o: ../Source/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\moham\Desktop\Embedded\WorkSpace\AVRRTOS\Source\portable\GCC\ATMega323" -I"C:\Users\moham\Desktop\Embedded\WorkSpace\AVRRTOS\Source\portable\MemMang" -I"C:\Users\moham\Desktop\Embedded\WorkSpace\AVRRTOS\Source\include" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


