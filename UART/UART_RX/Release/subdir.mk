################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Program.c \
../LCD_Program.c \
../ReceiveData.c \
../UART_program.c 

OBJS += \
./DIO_Program.o \
./LCD_Program.o \
./ReceiveData.o \
./UART_program.o 

C_DEPS += \
./DIO_Program.d \
./LCD_Program.d \
./ReceiveData.d \
./UART_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


