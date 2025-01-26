#include "led.h"

#define LD2_PIN 0x00000020

void led_init() //gives clock access to led I/O port A and sets led pin as OUTPUT
{
	RCC->AHB1ENR |= GPIOA_ENABLE;

	GPIOA->MODER |= (1U<<10); //Sets the 10th bit of the moder register to 1
	GPIOA->MODER &= ~(1U<<11);//Sets the 11th bit to 0
}
void led_on()
{
	GPIOA->ODR |= LD2_PIN;
}
void led_off()
{
	GPIOA->ODR &= ~LD2_PIN;
}


