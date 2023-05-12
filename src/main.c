/*
*
* main.c | The entry point
* (c) The Lennox Project & Copy05 2023
*
*/

#include "basics.h"
#include "utils/color.h"
#include "terminal/terminal.h"
#include "drivers/keyboard/keyboard.h"
#include "utils/err.h"

int main(){
	cls();
	printt("Loading Lennox 1.0 x86_64", WHITE);
	newline();
	_sleep(2000);
	printt("Loaded", BRIGHT_GREEN);
	return 0;
}
