#include<stdio.h>
#include "uart.h"
#include "stm32f4xx.h"
int __io_putchar(int ch)
{
	uart_write(ch);
	return ch;
}
static void uart_set_baud_rate(uint32_t peripheral_clock, uint32_t desired_baudrate)
{
	double mantissa;
	double fraction;

	uint16_t USARTDIV_MANT;
	uint16_t USARTDIV_FRAC;

	//Following calculation is defined in the reference manual, page 518, section 19.3.4.

	//Calculate the mantissa using the above formula and store in a temp double
	     mantissa = (double)peripheral_clock / (double)(desired_baudrate * 16);

	//Calculate the fraction using the above formula and store in a temp double|
	     fraction = ((mantissa - ((long)mantissa))) * 16;

	//Round the fraction double up if fractional portion of fraction is > .50
	     if (fraction - ((long)fraction) >= .5)
	        fraction++;

	// Store the mantissa into a uint16_t value (USARTDIV_MANT)
	// which stores only the whole portion of the mantissa double
	     USARTDIV_MANT = mantissa;

	//Store the fraction into a unit16_t value (USARTDIV_FRACT
	// which stores only the whole portion of the fraction double
	     USARTDIV_FRAC = fraction;

	//Set the 1st 4 bits [3:0] of the USART_BRR register to USARTDIV's fraction
	     USART2->BRR = (USARTDIV_FRAC << 0);

	//Set the next 12 bits [11:0] of the USART_BRR to USARTDIV's mantissa
	     USART2->BRR |= (USARTDIV_MANT << 4);
}

void uart_tx_init()
{
	//Enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOA_ENABLE;

	//Set PA2 to alternate function mode
	GPIOA->MODER |= (1U<<5); //Sets the 5th bit of the moder register to 1
	GPIOA->MODER &= ~(1U<<4); //Sets the 5th bit of the moder register to 0

	//Set alternate function type to AF8 (USART2_TX)
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

	//Enable clock access to USART 2
	RCC->APB1ENR |= USART2_ENABLE;

	uart_set_baud_rate(APB1_CLK, UART_BAUDRATE);

	//Enable UART2 and its Transmitter through control register 1 (also reseting it)
	USART2->CR1=CR1_UART_AND_TX_ENABLE;
}

void uart_write(int ch)
{
	//Check if data transmitter register is empty
	while(!USART2->SR&&SR_TX){}

	//Write to the data transmitter register
	USART2->DR=(ch&0xFF);
}
