################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/ILI9341_Display_Driver/third/GraphicsDisplay.cpp \
../Drivers/ILI9341_Display_Driver/third/SPI_TFT_ILI9341.cpp \
../Drivers/ILI9341_Display_Driver/third/TextDisplay.cpp 

OBJS += \
./Drivers/ILI9341_Display_Driver/third/GraphicsDisplay.o \
./Drivers/ILI9341_Display_Driver/third/SPI_TFT_ILI9341.o \
./Drivers/ILI9341_Display_Driver/third/TextDisplay.o 

CPP_DEPS += \
./Drivers/ILI9341_Display_Driver/third/GraphicsDisplay.d \
./Drivers/ILI9341_Display_Driver/third/SPI_TFT_ILI9341.d \
./Drivers/ILI9341_Display_Driver/third/TextDisplay.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ILI9341_Display_Driver/third/GraphicsDisplay.o: ../Drivers/ILI9341_Display_Driver/third/GraphicsDisplay.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Core/Inc -I"/Users/Tyler/Desktop/ece153b/final/Drivers/ILI9341_Display_Driver/third" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Drivers/ILI9341_Display_Driver/third/GraphicsDisplay.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/ILI9341_Display_Driver/third/SPI_TFT_ILI9341.o: ../Drivers/ILI9341_Display_Driver/third/SPI_TFT_ILI9341.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Core/Inc -I"/Users/Tyler/Desktop/ece153b/final/Drivers/ILI9341_Display_Driver/third" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Drivers/ILI9341_Display_Driver/third/SPI_TFT_ILI9341.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/ILI9341_Display_Driver/third/TextDisplay.o: ../Drivers/ILI9341_Display_Driver/third/TextDisplay.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Core/Inc -I"/Users/Tyler/Desktop/ece153b/final/Drivers/ILI9341_Display_Driver/third" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Drivers/ILI9341_Display_Driver/third/TextDisplay.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

