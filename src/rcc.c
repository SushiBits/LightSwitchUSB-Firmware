/*
 * rcc.c
 *
 *  Created on: Dec 3, 2017
 *      Author: technix
 */

#include <stm32f0xx.h>

void SystemInit(void)
{
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY));

	RCC->CFGR = RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR_PLLMUL6;
	RCC->CFGR2 = 0;
	__DSB();
	RCC->CR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY));

	FLASH->ACR |= FLASH_ACR_LATENCY;
	__DSB();

	SET_FIELD(RCC->CFGR, RCC_CFGR_SW, RCC_CFGR_SW_PLL);
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}
