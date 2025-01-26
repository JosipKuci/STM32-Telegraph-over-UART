#ifndef LED_H
#define LED_H
#include "stm32f4xx.h"
#define GPIOA_ENABLE 0x00000001
void led_init();
void led_on();
void led_off();

#endif
