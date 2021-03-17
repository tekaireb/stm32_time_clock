#include "LED.h"

void LED_Init(void) {
	// Enable GPIO Clocks
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;	// Enable clock of Port B (PB2)
//	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;	// Enable clock of Port E (PE8)

	// Initialize Red LED
	GPIOB->MODER &= ~(3UL << 4);	// Clear mode for pin 2 (bits 4, 5)
	GPIOB->MODER |= 1UL << 4;		// Set mode to 01: general purpose output mode
	GPIOB->OTYPER &= ~(1UL << 2);	// Set output type to 0: push-pull
	GPIOB->PUPDR &= ~(3UL << 4);	// PUPD = 00: no pull-up, no pull-down

//	// Initialize Green LED
//	GPIOE->MODER &= ~(3UL << 16);	// Clear mode for pin 8 (bits 16, 17)
//	GPIOE->MODER |= 1UL << 16;		// Set mode to 01: general purpose output mode
//	GPIOE->OTYPER &= ~(1UL << 8);	// Set output type to 0: push-pull
//	GPIOE->PUPDR &= ~(3UL << 16);	// PUPD = 00: no pull-up, no pull-down
}

void Red_LED_Off(void) {
	GPIOB->ODR &= ~(1UL << 2);	// Turn off red LED (PB2)
}

void Red_LED_On(void) {
	GPIOB->ODR |= 1UL << 2;		// Turn on red LED (PB2)
}

void Red_LED_Toggle(void){
	GPIOB->ODR ^= 1UL << 2;		// Toggle red LED (PB2)
}

void Green_LED_Off(void) {
	GPIOE->ODR &= ~(1UL << 8); 	// Turn off green LED (PE8)
}

void Green_LED_On(void) {
	GPIOE->ODR |= 1UL << 8; 	// Turn on green LED (PE8)
}

void Green_LED_Toggle(void) {
	GPIOE->ODR ^= 1UL << 8;		// Toggle green LED (PE8)
}
