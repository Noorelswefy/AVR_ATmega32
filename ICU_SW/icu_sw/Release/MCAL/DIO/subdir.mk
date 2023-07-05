################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO/DIO_program.c 

OBJS += \
./MCAL/DIO/DIO_program.o 

C_DEPS += \
./MCAL/DIO/DIO_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/DIO/%.o: ../MCAL/DIO/%.c MCAL/DIO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\noor elswefy\Documents\Eclipse\icu_sw\APP" -I"C:\Users\noor elswefy\Documents\Eclipse\icu_sw\LIB" -I"C:\Users\noor elswefy\Documents\Eclipse\icu_sw\HAL" -I"C:\Users\noor elswefy\Documents\Eclipse\icu_sw\HAL\LCD" -I"C:\Users\noor elswefy\Documents\Eclipse\icu_sw\MCAL" -I"C:\Users\noor elswefy\Documents\Eclipse\icu_sw\MCAL\DIO" -I"C:\Users\noor elswefy\Documents\Eclipse\icu_sw\MCAL\INT0" -I"C:\Users\noor elswefy\Documents\Eclipse\icu_sw\MCAL\Timer1" -I"C:\Users\noor elswefy\Documents\Eclipse\icu_sw\MCAL\Timer0" -I"C:\Users\noor elswefy\Documents\Eclipse\icu_sw\MCAL\GIE" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


