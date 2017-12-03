/*
 * stm32f0xx_it.h
 *
 *  Created on: Nov 8, 2017
 *      Author: technix
 */

#include <stm32f0xx.h>

extern void (*ISR_Vector[])(void);

#define IRQN_HANDLER(irqn, name) extern void name ##_IRQHandler(void);
#define SKIP_HANDLER(irqn)
#include <stm32f0xx_handler.h>
#undef IRQN_HANDLER
#undef SKIP_HANDLER
