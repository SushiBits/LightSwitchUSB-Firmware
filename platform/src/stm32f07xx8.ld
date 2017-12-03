/*
 * stm32f07xx8.ld
 *
 *  Created on: Nov 8, 2017
 *      Author: technix
 */

MEMORY
{
	IROM    (r x) : ORIGIN = 0x08000000, LENGTH = 64k
	IRAM    (rwx) : ORIGIN = 0x20000000, LENGTH = 16k
}
