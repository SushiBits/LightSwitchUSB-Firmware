/*
 * board.c
 *
 *  Created on: Sep 24, 2017
 *      Author: technix
 */

#include <dreamos-rt/gpio.h>
#include <stdio.h>
#include <stm32f0xx.h>

__attribute__((constructor(1001))) void board_init(void)
{
	static const int pinModes[] =
	{
			// Pin Mode					// GPIO	Pin	Function
			// GPIOA
			-1,							// PA0	6
			-1,							// PA1	7
			AFIO(GPIO_MODE_AF1),			// PA2	8	DBG_TX
			AFIO_PU(GPIO_MODE_AF1),		// PA3	9	DBG_RX
			-1,							// PA4	10
			-1,							// PA5	11
			AFIO(GPIO_MODE_AF1),			// PA6	12	SYS_LED
			-1,							// PA7	13

			-1,							// PA8
			-1,							// PA9
			-1,							// PA10
			ANALOG,						// PA11	17	USB_DM
			ANALOG,						// PA12	18	USB_DP
			-1,							// PA13	19	DBG_TMS
			-1,							// PA14	20	DBG_TCK
			-1,							// PA15

			// GPIOB
			-1,							// PB0
			AFIO(GPIO_MODE_AF1),			// PB1	14	OUTPUT_LED
			-1,							// PB2
			-1,							// PB3
			-1,							// PB4
			-1,							// PB5
			-1,							// PB6
			-1,							// PB7

			-1,							// PB8	1
			-1,							// PB9
			-1,							// PB10
			-1,							// PB11
			-1,							// PB12
			-1,							// PB13
			-1,							// PB14
			-1,							// PB15
	};

	for (uint8_t pin = 0; pin < sizeof(pinModes) / sizeof(int); pin++)
	{
		int mode = pinModes[pin];
		if (mode > 0)
			pinMode(pin, mode);
	}
}
