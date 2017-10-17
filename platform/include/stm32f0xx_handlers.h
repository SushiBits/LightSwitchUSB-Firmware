/*
 * stm32f0xx_handlers.h
 *
 *  Created on: Oct 17, 2017
 *      Author: technix
 */

#ifndef HANDLER
#include <stm32f0xx_it.h>
#else

// Cortex-M0 Processor Exceptions Numbers
HANDLER(NonMaskableInt, -14)             // 2 Non Maskable Interrupt
HANDLER(HardFault, -13)                  // 3 Cortex-M0 Hard Fault Interrupt
SKIP_HANDLER                             // 4
SKIP_HANDLER                             // 5
SKIP_HANDLER                             // 6
SKIP_HANDLER                             // 7
SKIP_HANDLER                             // 8
SKIP_HANDLER                             // 9
SKIP_HANDLER                             // 10
HANDLER(SVC, -5)                         // 11 Cortex-M0 SV Call Interrupt
SKIP_HANDLER                             // 12
SKIP_HANDLER                             // 13
HANDLER(PendSV, -2)                      // 14 Cortex-M0 Pend SV Interrupt
HANDLER(SysTick, -1)                     // 15 Cortex-M0 System Tick Interrupt

// STM32F0 specific Interrupt Numbers
HANDLER(WWDG, 0)                         // Window WatchDog Interrupt
HANDLER(PVD_VDDIO2, 1)                   // PVD & VDDIO2 Interrupt through EXTI Lines 16 and 31
HANDLER(RTC, 2)                          // RTC Interrupt through EXTI Lines 17, 19 and 20
HANDLER(FLASH, 3)                        // FLASH global Interrupt
HANDLER(RCC_CRS, 4)                      // RCC & CRS global Interrupt
HANDLER(EXTI0_1, 5)                      // EXTI Line 0 and 1 Interrupt
HANDLER(EXTI2_3, 6)                      // EXTI Line 2 and 3 Interrupt
HANDLER(EXTI4_15, 7)                     // EXTI Line 4 to 15 Interrupt
HANDLER(TSC, 8)                          // Touch Sensing Controller Interrupts
HANDLER(DMA1_Channel1, 9)                // DMA1 Channel 1 Interrupt
HANDLER(DMA1_Channel2_3, 10)             // DMA1 Channel 2 and Channel 3 Interrupt
HANDLER(DMA1_Channel4_5, 11)             // DMA1 Channel 4 and Channel 5 Interrupt
HANDLER(ADC1, 12)                        // ADC1 Interrupt
HANDLER(TIM1_BRK_UP_TRG_COM, 13)         // TIM1 Break, Update, Trigger and Commutation Interrupt
HANDLER(TIM1_CC, 14)                     // TIM1 Capture Compare Interrupt
HANDLER(TIM2, 15)                        // TIM2 global Interrupt
HANDLER(TIM3, 16)                        // TIM3 global Interrupt
SKIP_HANDLER
SKIP_HANDLER
HANDLER(TIM14, 19)                       // TIM14 global Interrupt
SKIP_HANDLER
HANDLER(TIM16, 21)                       // TIM16 global Interrupt
HANDLER(TIM17, 22)                       // TIM17 global Interrupt
HANDLER(I2C1, 23)                        // I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)
SKIP_HANDLER
HANDLER(SPI1, 25)                        // SPI1 global Interrupt
HANDLER(SPI2, 26)                        // SPI2 global Interrupt
HANDLER(USART1, 27)                      // USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup)
HANDLER(USART2, 28)                      // USART2 global Interrupt
SKIP_HANDLER
HANDLER(CEC_CAN, 30)                     // CEC and CAN global Interrupts & EXTI Line27 Interrupt
HANDLER(USB, 31)                         // USB global Interrupt  & EXTI Line18 Interrupt

#endif
