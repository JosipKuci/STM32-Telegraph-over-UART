################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/button.c \
../Src/delay.c \
../Src/led.c \
../Src/main.c \
../Src/morse_tree.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/uart.c 

OBJS += \
./Src/button.o \
./Src/delay.o \
./Src/led.o \
./Src/main.o \
./Src/morse_tree.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/uart.o 

C_DEPS += \
./Src/button.d \
./Src/delay.d \
./Src/led.d \
./Src/main.d \
./Src/morse_tree.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F411xE -c -I../Inc -I"F:/ST-RTOS/Nucleo-f411re-projects/uart_morse_code/headers/CMSIS/Include" -I"F:/ST-RTOS/Nucleo-f411re-projects/uart_morse_code/headers/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/button.cyclo ./Src/button.d ./Src/button.o ./Src/button.su ./Src/delay.cyclo ./Src/delay.d ./Src/delay.o ./Src/delay.su ./Src/led.cyclo ./Src/led.d ./Src/led.o ./Src/led.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/morse_tree.cyclo ./Src/morse_tree.d ./Src/morse_tree.o ./Src/morse_tree.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/uart.cyclo ./Src/uart.d ./Src/uart.o ./Src/uart.su

.PHONY: clean-Src

