/*
*
* interrupt.c | Interrupt handling
* (c) The Lennox Project & Copy05 2023
*
*/


#include <Lennox/basics.h>

typedef void (*interrupt_t)(void);

void interrupt(u8 irq, interrupt_t handler);
