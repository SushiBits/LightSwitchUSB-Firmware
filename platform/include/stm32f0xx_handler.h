/*
 * This file auto includes the handler macro files. It is intended to be
 * included multiple times.
 */

#if defined(STM32F030x6)
  #include "stm32f030x6_handler.h"
#elif defined(STM32F030x8)
  #include "stm32f030x8_handler.h"
#elif defined(STM32F031x6)
  #include "stm32f031x6_handler.h"
#elif defined(STM32F038xx)
  #include "stm32f038xx_handler.h"
#elif defined(STM32F042x6)
  #include "stm32f042x6_handler.h"
#elif defined(STM32F048xx)
  #include "stm32f048xx_handler.h"
#elif defined(STM32F051x8)
  #include "stm32f051x8_handler.h"
#elif defined(STM32F058xx)
  #include "stm32f058xx_handler.h"
#elif defined(STM32F070x6)
  #include "stm32f070x6_handler.h"
#elif defined(STM32F070xB)
  #include "stm32f070xb_handler.h"
#elif defined(STM32F071xB)
  #include "stm32f071xb_handler.h"
#elif defined(STM32F072xB)
  #include "stm32f072xb_handler.h"
#elif defined(STM32F078xx)
  #include "stm32f078xx_handler.h"
#elif defined(STM32F091xC)
  #include "stm32f091xc_handler.h"
#elif defined(STM32F098xx)
  #include "stm32f098xx_handler.h"
#elif defined(STM32F030xC)
  #include "stm32f030xc_handler.h"    
#else
 #error "Please select first the target STM32F0xx device used in your application (in stm32f0xx.h file)"
#endif

