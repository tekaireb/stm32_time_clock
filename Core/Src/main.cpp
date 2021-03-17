
#include <lcd.hpp>
#include <EXTI.hpp>
#include <main.hpp>
#include <time.h>

#include <pages/Page.hpp>
#include <pages/MainPage.hpp>
#include <pages/EmployeeListPage.hpp>
#include <pages/EmployeeProfilePage.hpp>
#include <pages/PayrollPage.hpp>
#include <pages/HelpPage.hpp>

#include "stm32l4xx_hal_rtc.h"

extern "C" {
#include "UART.h"
#include "RTC.h"
}

void get_time(time_t& t) {
	struct tm datetime;

	datetime.tm_year = RTC_DATE_GetYear();
	datetime.tm_mon  = RTC_DATE_GetMonth();
	datetime.tm_mday = RTC_DATE_GetDay();

	datetime.tm_hour = RTC_TIME_GetHour();
	datetime.tm_min  = RTC_TIME_GetMinute();
	datetime.tm_sec  = RTC_TIME_GetSecond();

	t = mktime(&datetime);
}

int main(void) {
	HAL_Init();
	SystemClock_Config(); // 80 MHz PLL ON
	EXTI_Init();

	lcd_start();

	UART1_Init();
	UART1_GPIO_Init();
	USART_Init(USART1);

	RTC_Init();

	// Add pages
	Page* p = new MainPage((char*) "main");
	add_page(p);
	p = new EmployeeListPage((char*) "employees");
	add_page(p);
	p = new EmployeeProfilePage((char*) "profile");
	add_page(p);
	p = new PayrollPage((char*) "payroll");
	add_page(p);
	p = new HelpPage((char*) "help");
	add_page(p);

	get_page((char*) "main")->make_active();

	__enable_irq();

	int id;
	time_t t;

	// while (1);

	while (1) {
		printf("Enter employee ID: \n");

		scanf("%d", &id);

		get_time(t);

		Employee * e = get_employee(id);
		int clock_in = !e->events[e->num_events - 1].clock_in;
		add_event(id, clock_in, t);

		printf(clock_in ? "Clocked in.\n" : "Clocked out.\n");
		printf("This event has been recorded.\n");
//	}
}










// STM Boilerplate:

/**
  * @brief  System Clock Configuration on USB/ST-Link
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (MSI)
  *            SYSCLK(Hz)                     = 80000000
  *            HCLK(Hz)                       = 80000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            MSI Frequency(Hz)              = 2000000
  *            PLL_M                          = 1
  *            PLL_N                          = 80
  *            PLL_R                          = 2
  *            PLL_P                          = 7
  *            PLL_Q                          = 4
  *            Flash Latency(WS)              = 4
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  /* oscillator and clocks configs */
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  
  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();

  if(HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /* Disable Power Control clock */
  __HAL_RCC_PWR_CLK_DISABLE();

  /* 80 Mhz from PLL with MSI 8Mhz as source clock */
  /* MSI is enabled after System reset, activate PLL with MSI as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_7;   /* 8 Mhz */
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 20;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLP = 7;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  __HAL_RCC_SYSCFG_CLK_ENABLE();

}

void Error_Handler(void)
{
  /* Init Error Led Red */
  BSP_LED_Init(LED_RED);

  /* Turn Led Red on */
  BSP_LED_On(LED_RED);

  while(1);
}
