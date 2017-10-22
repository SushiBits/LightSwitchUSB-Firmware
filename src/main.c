/*
 * main.c
 *
 *  Created on: Oct 17, 2017
 *      Author: technix
 */

#include <stm32f0xx.h>

#include "led.h"

int main(void)
{
	for (;;)
	{
		int value = 0;

		value = led_update() || value;

		if (!value)
			__WFI();
	}
}
