/*
 * main.hpp
 *
 *  Created on: Mar 2, 2021
 *      Author: Tyler
 */

#ifndef __MAIN_H
#define __MAIN_H

#include "../../Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery.h"

#ifdef __cplusplus
	extern "C" {
#endif
   
#include "stm32l4xx_hal.h"
#include "stm32l4xx_it.h"

#include "stm32l4xx_hal_qspi.h"

void SystemClock_Config(void);
void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

