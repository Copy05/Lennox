/*
*
* main.c | The entry point
* (c) The Lennox Project & Copy05 2023
*
*/

#include <Lennox/basics.h>
#include <Lennox/color.h>
#include <Lennox/terminal.h>
#include <Lennox/drivers/keyboard.h>
#include <Lennox/err.h>
#include <Lennox/interrupt.h>

// Keyboard Handling
char buffer[256];
u32 buf_pos = 0;

int main(){
	cls();
	printt("Loading Lennox 1.0 x86_64", WHITE);
	newline();
	_sleep(2000);
	printt("Loaded", BRIGHT_GREEN);
	newline();
	interrupt(0x21, keyboard_handler);
	return 0;
}
