################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Program.c \
../GIE_program.c \
../ICU_SW.c \
../INT0_program.c \
../LCD_Program.c \
../Timer0_prog.c \
../Timer1_program.c 

OBJS += \
./DIO_Program.o \
./GIE_program.o \
./ICU_SW.o \
./INT0_program.o \
./LCD_Program.o \
./Timer0_prog.o \
./Timer1_program.o 

C_DEPS += \
./DIO_Program.d \
./GIE_program.d \
./ICU_SW.d \
./INT0_program.d \
./LCD_Program.d \
./Timer0_prog.d \
./Timer1_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


