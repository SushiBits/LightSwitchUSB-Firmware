/*
 * stm32f03xx4.ld
 *
 *  Created on: Nov 8, 2017
 *      Author: technix
 */

MEMORY
{
	IROM    (r x) : ORIGIN = 0x08000000, LENGTH = 16k
	IRAM    (rwx) : ORIGIN = 0x20000000, LENGTH = 4k
}
