/*
 * led.c
 *
 *  Created on: Oct 18, 2017
 *      Author: technix
 */

#include <stm32f0xx.h>
#include <stm32f0xx_it.h>

uint16_t brightness = 0;

__attribute__((constructor(2000))) void led_init(void)
{

}

// Main LED
void led_set(uint16_t value)
{

}

// Status LED

