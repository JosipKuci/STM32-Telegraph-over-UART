/*
 * button.h
 *
 *  Created on: Jan 25, 2025
 *      Author: Josip Šimun Kuči
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#define GPIOC_ENABLE 0b100
#define BTN_PULLUP_ENABLE 0x01000000
void button_init();

#endif /* BUTTON_H_ */
