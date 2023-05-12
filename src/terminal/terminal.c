/*
*
* terminal.h | Terminal output
* (c) The Lennox Project & Copy05 2023
*
*/

#include "terminal.h"
#include "../std/stdlib.h"

static u32 nl_idx = 1;
u16* vga_buffer = VGA_ADDR;
u32 vga_index = 0;

void cls(void){
	for(u32 i = 0; i < 80 * 25 * 2; i += 2){
		vga_buffer[i] = ' ';
	}
}

void printt(char* str, u8 color){
	u32 i = 0;
	while(str[i]){
		vga_buffer[vga_index] = (u16)str[i] | (u16)color << 0x08;
		i++;
		vga_index++;
	}
}

void newline(){
	if(nl_idx >= 55)
		nl_idx = 0;
	vga_index = 80 * nl_idx;
	nl_idx++;
}

void printchar(char str, u8 color){
	vga_buffer[vga_index] = str | (u16)color << 0x08;
	vga_index++;
}

void _sleep(u32 ms){
	typedef unsigned long ul32;

	ul32 real_ms = ms * 100000;
	for(ul32 i = 0; i < real_ms; i++)
		asm volatile("NOP ");
}
