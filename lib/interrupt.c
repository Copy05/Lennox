/*
*
* interrupt.c | Interrupt handling
* (c) The Lennox Project & Copy05 2023
*
*/

#include <Lennox/interrupt.h>

void interrupt(u8 irq, interrupt_t handler){
	interrupt_t* intv = (interrupt_t)0x10000;
	intv[irq] = handler;
}
