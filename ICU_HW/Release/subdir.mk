################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Program.c \
../GIE_program.c \
../Icu_hw.c \
../LCD_Program.c \
../Timer1_program.c 

OBJS += \
./DIO_Program.o \
./GIE_program.o \
./Icu_hw.o \
./LCD_Program.o \
./Timer1_program.o 

C_DEPS += \
./DIO_Program.d \
./GIE_program.d \
./Icu_hw.d \
./LCD_Program.d \
./Timer1_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

