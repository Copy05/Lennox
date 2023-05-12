/*
*
* terminal.h | Terminal output
* (c) The Lennox Project & Copy05 2023
*
*/

#include "../basics.h"

#define VGA_ADDR 0xB8000;

void printt(char* str, u8 color);
void printchar(char str, u8 color);
void cls(void);
void _sleep(u32 ms);
