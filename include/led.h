/*
 * led.h
 *
 *  Created on: Oct 20, 2017
 *      Author: technix
 */

#ifndef INCLUDE_LED_H_
#define INCLUDE_LED_H_

#include <stdint.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

extern uint16_t brightness;

int led_update(void);

__END_DECLS

#endif /* INCLUDE_LED_H_ */
