/*
 * button.c
 *
 *  Created on: Jan 25, 2025
 *      Author: Josip Šimun Kuči
 */
#include "stm32f4xx.h"
#include "button.h"
void button_init()
{
	RCC->AHB1ENR |= GPIOC_ENABLE;
	GPIOC->PUPDR |= BTN_PULLUP_ENABLE;
}
