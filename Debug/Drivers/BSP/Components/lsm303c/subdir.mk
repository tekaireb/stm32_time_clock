################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/lsm303c/lsm303c.c 

C_DEPS += \
./Drivers/BSP/Components/lsm303c/lsm303c.d 

OBJS += \
./Drivers/BSP/Components/lsm303c/lsm303c.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/lsm303c/lsm303c.o: ../Drivers/BSP/Components/lsm303c/lsm303c.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Core/Inc -I"/Users/Tyler/Desktop/ece153b/final/Drivers/ILI9341_Display_Driver/third" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/lsm303c/lsm303c.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

