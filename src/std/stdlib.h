/*
*
* std/stdlib.h | A reduced version of <stdlib.h>
* (c) The Lennox Project & Copy05 2023
*
*/

#include "../basics.h"
#include "../terminal/terminal.h"

u32 strlen(const char* str);
void printf(const char* format, ...);
void *memset(void *dst, char c, u32 n);
