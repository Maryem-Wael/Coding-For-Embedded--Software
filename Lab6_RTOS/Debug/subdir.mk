################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Challenge1.c 

OBJS += \
./Challenge1.o 

C_DEPS += \
./Challenge1.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\moham\Desktop\Embedded\WorkSpace\AVRRTOS\Source\include" -I"C:\Users\moham\Desktop\Embedded\WorkSpace\AVRRTOS\Source\portable\MemMang" -I"C:\Users\moham\Desktop\Embedded\WorkSpace\AVRRTOS\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


