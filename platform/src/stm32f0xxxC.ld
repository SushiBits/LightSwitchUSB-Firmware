/*
 * stm32f0xxxC.ld
 *
 *  Created on: Nov 8, 2017
 *      Author: technix
 */

MEMORY
{
	IROM    (r x) : ORIGIN = 0x08000000, LENGTH = 256k
	IRAM    (rwx) : ORIGIN = 0x20000000, LENGTH = 32k
}
