#include "UART.h"

void UART1_Init(void) {
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;	// Enable USART1 Clock
	RCC->CCIPR &= ~RCC_CCIPR_USART1SEL;		// Clear
	RCC->CCIPR |= RCC_CCIPR_USART1SEL_0;	// Select the system clock as the USART1 clock source
}

void UART2_Init(void) {
	RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;	// Enable USART2 Clock
	RCC->CCIPR &= ~RCC_CCIPR_USART2SEL;		// Clear
	RCC->CCIPR |= RCC_CCIPR_USART2SEL_0;	// Select the system clock as the USART2 clock source
}

void UART1_GPIO_Init(void) {
	// Enable GPIO Port B Clock
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

	// Set PB6 and PB7 mode to AF (0b10)
	GPIOB->MODER &= ~(0xf << 12);			// Clear bits for PB6 and PB7
	GPIOB->MODER |= 0xa << 12;				// Set PB6 and PB7 mode to AF (0b10)

	// Set PB6 and PB7 to Very High Speed (0b11)
	GPIOB->OSPEEDR |= 3 << 12 | 3 << 14;

	// Set output type to push-pull (0b0)
	GPIOB->OTYPER &= ~(1 << 6 | 1 << 7);

	// Set PB6 and PB7 to use pull-up resistors (0b01)
	GPIOB->PUPDR &= ~(0xf << 12);			// Clear bits for PB6 and PB7
	GPIOB->PUPDR |= 0x5 << 12;				// Set PB6 and PB7 to pull-up (0b01)

	// Clear AFSEL6/7 and set to AF7
    GPIOB->AFR[0] &= ~(0xff << 24);
    GPIOB->AFR[0] |= 7 << 24 | 7 << 28;		// Set AFSEL6/7 to 7
}

void UART2_GPIO_Init(void) {
	// Enable GPIO Port D Clock
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIODEN;

	// Set PD5 and PD6 mode to AF (0b10)
	GPIOD->MODER &= ~(0xf << 10);			// Clear bits for PD5 and PD6
	GPIOD->MODER |= 0xa << 10;				// Set PD5 and PD6 mode to AF (0b10)

	// Set PD5 and PD6 to Very High Speed (0b11)
	GPIOD->OSPEEDR |= 3 << 10 | 3 << 12;

	// Set output type to push-pull (0b0)
	GPIOD->OTYPER &= ~(1 << 5 | 1 << 6);

	// Set PD5 and PD6 to use pull-up resistors (0b01)
	GPIOD->PUPDR &= ~(0xf << 10);			// Clear bits for PD5 and PD6
	GPIOD->PUPDR |= 0x5 << 10;				// Set PD5 and PD6 to pull-up (0b01)

	// Clear AFSEL5/6 and set to AF7
    GPIOD->AFR[0] &= ~(0xff << 20);
    GPIOD->AFR[0] |= 7 << 20 | 7 << 24;		// Set AFSEL5/6 to 7
}

void USART_Init(USART_TypeDef* USARTx) {
	USARTx->CR1 &= ~USART_CR1_UE;			// Disable USART before initializing

	USARTx->CR1 &= ~USART_CR1_M;			// Set word length to 8 (0b00)
	USARTx->CR1 &= ~USART_CR1_OVER8;		// Over-sample by 16
	USARTx->CR2 &= ~USART_CR2_STOP;			// Set 1 stop bit

	// Baud rate = f_CLK / USARTDIV --> USARTDIV = f_CLK / Baud rate = 80 MHz / 9600 = 8333.33
	USARTx->BRR |= 8333;					// Set baud rate to 9600

	USARTx->CR1 |= USART_CR1_TE;			// Enable Transmitter
	USARTx->CR1 |= USART_CR1_RE;			// Enable Receiver

	USARTx->CR1 |= USART_CR1_UE;			// Enable USART
}

uint8_t USART_Read (USART_TypeDef * USARTx) {
	// SR_RXNE (Read data register not empty) bit is set by hardware
	while (!(USARTx->ISR & USART_ISR_RXNE));  // Wait until RXNE (RX not empty) bit is set
	// USART resets the RXNE flag automatically after reading DR
	return ((uint8_t)(USARTx->RDR & 0xFF));
	// Reading USART_DR automatically clears the RXNE flag
}

void USART_Write(USART_TypeDef * USARTx, uint8_t *buffer, uint32_t nBytes) {
	int i;
	// TXE is cleared by a write to the USART_DR register.
	// TXE is set by hardware when the content of the TDR
	// register has been transferred into the shift register.
	for (i = 0; i < nBytes; i++) {
		while (!(USARTx->ISR & USART_ISR_TXE));   	// wait until TXE (TX empty) bit is set
		// Writing USART_DR automatically clears the TXE flag
		USARTx->TDR = buffer[i] & 0xFF;
		USART_Delay(300);
	}
	while (!(USARTx->ISR & USART_ISR_TC));   		  // wait until TC bit is set
	USARTx->ISR &= ~USART_ISR_TC;
}

void USART_Delay(uint32_t us) {
	uint32_t time = 100*us/7;
	while(--time);
}
