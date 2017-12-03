/*
 * stm32f07xx6.ld
 *
 *  Created on: Nov 8, 2017
 *      Author: technix
 */

MEMORY
{
	IROM    (r x) : ORIGIN = 0x08000000, LENGTH = 32k
	IRAM    (rwx) : ORIGIN = 0x20000000, LENGTH = 6k
}
