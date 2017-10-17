/*
 * stm32f0xx_it.h
 *
 *  Created on: Oct 17, 2017
 *      Author: technix
 */

#ifndef PLATFORM_INCLUDE_STM32F0XX_IT_H_
#define PLATFORM_INCLUDE_STM32F0XX_IT_H_

#include <sys/cdefs.h>

__BEGIN_DECLS

extern void (*isr_vector[])(void);

#define HANDLER(name, id) extern void name##_IRQHandler(void);
#define SKIP_HANDLER
#include <stm32f0xx_handlers.h>
#undef SKIP_HANDLER
#undef HANDLER

__END_DECLS

#endif /* PLATFORM_INCLUDE_STM32F0XX_IT_H_ */
