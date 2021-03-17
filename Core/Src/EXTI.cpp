#include <EXTI.hpp>
#include "lcd.hpp"

#include <pages/MainPage.hpp>
#include <pages/EmployeeListPage.hpp>
#include <pages/EmployeeProfilePage.hpp>
#include <pages/PayrollPage.hpp>
#include <pages/HelpPage.hpp>


extern "C" {

void EXTI_Init(void) {
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;	// Enable GPIO Port A Clock

	// Initialize Joystick
	GPIOA->MODER &= ~(0xCFF);			// Clear mode for pins 0-3 + 5, mode = 00: input
	GPIOA->PUPDR &= ~(0xCFF);			// Clear PUPD
	GPIOA->PUPDR |= 0x8AA;				// For pins 0-3 + 5, PUPD = 10: pull-down

	// Configure SYSCFG EXTI
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0;		// Center
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;

	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI1;		// Left
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI1_PA;

	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI2;		// Right
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI2_PA;

	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI3;		// Up
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI3_PA;

	SYSCFG->EXTICR[1] &= ~SYSCFG_EXTICR2_EXTI5;		// Down
	SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI5_PA;

	// Configure EXTI Trigger
	EXTI->FTSR1 |= EXTI_FTSR1_FT0;	// Center
	EXTI->FTSR1 |= EXTI_FTSR1_FT1;	// Left
	EXTI->FTSR1 |= EXTI_FTSR1_FT2;	// Right
	EXTI->FTSR1 |= EXTI_FTSR1_FT3;	// Up
	EXTI->FTSR1 |= EXTI_FTSR1_FT5;	// Down

	/* Note:
	 * 	EXTI->RTSR1 |= EXTI_RTSR1_RTk;	// Rising edge trigger, pin k
	 *	EXTI->FTSR1 |= EXTI_FTSR1_FTk;	// Falling edge trigger, pin k
	 */

	// Enable EXTI
	EXTI->IMR1 |= EXTI_IMR1_IM0;	// Center
	EXTI->IMR1 |= EXTI_IMR1_IM1;	// Left
	EXTI->IMR1 |= EXTI_IMR1_IM2;	// Right
	EXTI->IMR1 |= EXTI_IMR1_IM3;	// Up
	EXTI->IMR1 |= EXTI_IMR1_IM5;	// Down

	// Configure and Enable in NVIC
	NVIC_EnableIRQ(EXTI0_IRQn);		// Center
	NVIC_SetPriority(EXTI0_IRQn, 0);

	NVIC_EnableIRQ(EXTI1_IRQn);		// Left
	NVIC_SetPriority(EXTI1_IRQn, 0);

	NVIC_EnableIRQ(EXTI2_IRQn);		// Right
	NVIC_SetPriority(EXTI2_IRQn, 0);

	NVIC_EnableIRQ(EXTI3_IRQn);		// Up
	NVIC_SetPriority(EXTI3_IRQn, 0);

	NVIC_EnableIRQ(EXTI9_5_IRQn);	// Down
	NVIC_SetPriority(EXTI9_5_IRQn, 0);
}

// INTERRUPT HANDLERS

// Center
void EXTI0_IRQHandler(void) {
	EXTI->PR1 |= EXTI_PR1_PIF0; // Clear interrupt pending bit

	active_page->center_button_handler();
}

// Left
void EXTI1_IRQHandler(void) {
	EXTI->PR1 |= EXTI_PR1_PIF1; // Clear interrupt pending bit

	active_page->left_button_handler();
}

// Right
void EXTI2_IRQHandler(void) {
	EXTI->PR1 |= EXTI_PR1_PIF2; // Clear interrupt pending bit

	active_page->right_button_handler();
}

// Up
void EXTI3_IRQHandler(void) {
	EXTI->PR1 |= EXTI_PR1_PIF3; // Clear interrupt pending bit

	active_page->up_button_handler();
}

// Down
void EXTI9_5_IRQHandler(void) {
	EXTI->PR1 |= EXTI_PR1_PIF5; // Clear interrupt pending bit

	active_page->down_button_handler();
}

}
