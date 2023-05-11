#include "basics.h"
#include "utils/color.h"
#include "terminal/terminal.h"
#include "drivers/keyboard/keyboard.h"

int main(){
	cls();
	printt("Loading Lennox 1.0 x86_64", WHITE);
	newline();
	_sleep(2000);
	printt("Loaded", BRIGHT_GREEN);
	newline();
	keyboard_handler();
	return 0;
}
