/*
 * stm32f0xx_it.c
 *
 *  Created on: Oct 17, 2017
 *      Author: technix
 */

#include <stm32f0xx_it.h>

#include <stm32f0xx.h>

#define COMPILING_NEWLIB
#include <stdint.h>
#include <string.h>
#include <unistd.h>

void __stack(void);
__attribute((noreturn)) void _start(void);
void Reset_IRQHandler(void);
void Default_IRQHandler(void);

__attribute__((section(".vector"))) void (*isr_vector[])(void) =
{
		__stack,
		Reset_IRQHandler,

#define HANDLER(name, id) name##_IRQHandler,
#define SKIP_HANDLER NULL,
#include <stm32f0xx_handlers.h>
#undef SKIP_HANDLER
#undef HANDLER
};

#define HANDLER(name, id) __attribute__((weak, alias("Default_IRQHandler"))) void name##_IRQHandler(void);
#define SKIP_HANDLER
#include <stm32f0xx_handlers.h>
#undef SKIP_HANDLER
#undef HANDLER

extern const struct copyitem
{
	const void *src;
	void *dst;
	uint32_t size;
} *__copy_addr;
extern uint32_t __copy_size;

extern const struct zeroitem
{
	void *dst;
	uint32_t size;
} *__zero_addr;
extern uint32_t __zero_size;

__attribute__((noreturn)) void Reset_IRQHandler(void)
{
	SystemInit();

	uint32_t count = __copy_size / sizeof(struct copyitem);
	for (uint32_t idx = 0; idx < count; idx++)
	{
		const struct copyitem *item = &(__copy_addr[idx]);
		memcpy(item->dst, item->src, item->size);
	}

	count = __zero_size / sizeof(struct zeroitem);
	for (uint32_t idx = 0; idx < count; idx++)
	{
		const struct zeroitem *item = &(__zero_addr[idx]);
		memset(item->dst, 0, item->size);
	}

	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGCOMPEN;
	__DSB();
	SET_FIELD(SYSCFG->CFGR1, SYSCFG_CFGR1_MEM_MODE, 0x3);
	__DSB();

	SystemCoreClockUpdate();

	_start();
}

#define DHCSR (*((volatile uint32_t *)0xe000edf0))

__attribute__((noreturn)) void Default_IRQHandler(void)
{
	if (DHCSR & 1)
		__BKPT(0);

	for (;;)
		__WFE();
}

__attribute__((noreturn)) void _exit(__attribute__((unused)) int status)
{
	if (DHCSR & 1)
		__BKPT(0);

	SCB->AIRCR = 0x05fa0000 | SCB_AIRCR_SYSRESETREQ_Msk;

	for (;;)
		__WFE();
}
