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
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	TIM3->ARR = 0xffff;
	TIM3->PSC = 0;
	TIM3->CNT = 0;
	TIM3->CR1 |= TIM_CR1_CEN;

	TIM3->CCMR1 = 0b01101000;
	TIM3->CCMR2 = 0b01101000 << 8;
	TIM3->CCER = TIM_CCER_CC1E | TIM_CCER_CC4E;

	TIM3->CCR1 = 0xffff;
	TIM3->CCR4 = 0;
}

// Main LED
int led_update(void)
{
	if (TIM3->CCR4 != brightness)
	{
		TIM3->CCR4 = brightness;
		return 1;
	}

	return 0;
}

// Status LED

