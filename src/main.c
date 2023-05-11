#include "basics.h"
#include "utils/color.h"
#include "terminal/terminal.h"
#include "drivers/keyboard/keyboard.h"

int main(){

	cls();
	printt("Loading Lennox v1.0 x86_64", WHITE);
	_sleep(12000000);
	newline();
	printt("Loaded", BRIGHT_BLUE);
	newline();
	keyboard_handler();
	return 0;
}
