################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery.c \
../Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_compass.c \
../Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_gyroscope.c \
../Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_idd.c \
../Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_qspi.c 

C_DEPS += \
./Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery.d \
./Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_compass.d \
./Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_gyroscope.d \
./Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_idd.d \
./Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_qspi.d 

OBJS += \
./Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery.o \
./Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_compass.o \
./Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_gyroscope.o \
./Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_idd.o \
./Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_qspi.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery.o: ../Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Core/Inc -I"/Users/Tyler/Desktop/ece153b/final/Drivers/ILI9341_Display_Driver/third" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_compass.o: ../Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_compass.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Core/Inc -I"/Users/Tyler/Desktop/ece153b/final/Drivers/ILI9341_Display_Driver/third" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_compass.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_gyroscope.o: ../Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_gyroscope.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Core/Inc -I"/Users/Tyler/Desktop/ece153b/final/Drivers/ILI9341_Display_Driver/third" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_gyroscope.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_idd.o: ../Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_idd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Core/Inc -I"/Users/Tyler/Desktop/ece153b/final/Drivers/ILI9341_Display_Driver/third" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_idd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_qspi.o: ../Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_qspi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Core/Inc -I"/Users/Tyler/Desktop/ece153b/final/Drivers/ILI9341_Display_Driver/third" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery_qspi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

