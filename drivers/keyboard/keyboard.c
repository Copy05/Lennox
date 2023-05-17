/*
*
* Keyboard.c | The keyboard driver
* (c) The Lennox Project & Copy05 2023
*
*/


#include <Lennox/basics.h>
#include <Lennox/drivers/keyboard.h>
#include <Lennox/color.h>
#include <Lennox/asm.h>

char convertToAscii(u8 scancode){
	// US-Keyboard Layout
	static const char scancode_map[128] = {
        	0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0, 0, // 0x00 to 0x0F
        	'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 0, 0, 'a', 's', // 0x10 to 0x1F
        	'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\', 'z', 'x', 'c', 'v', // 0x20 to 0x2F
        	'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' ', 0, 0, 0, 0, 0, 0, // 0x30 to 0x3F
        	0, 0, 0, 0, 0, 0, 0, '7', '8', '9', '-', '4', '5', '6', '+', '1', // 0x40 to 0x4F
        	'2', '3', '0', '.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0x50 to 0x5F
        	0, 0, 0, 0, 0, 0, 0, '7', '8', '9', '-', '4', '5', '6', '+', '1', // 0x60 to 0x6F
        	'2', '3', '0', '.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0x70 to 0x7F
    	};
    	if (scancode < 128)
        	return scancode_map[scancode];
    	else
        	return 0;
}

char getkeycode()
{
  char chars = 0;
  while((chars = inb(KEYBOARD_PORT)) != 0){
    if(chars > 0)
      return chars;
  }
  return chars;
}

void keyboard_handler(){
	u8 sc = inb(KEYBOARD_PORT);
	char c = convertToAscii(sc);

	if(c != 0x00) {
		if(buf_pos < 255) {
			buffer[buf_pos++] = c;
			printchar(c, WHITE);
		}
	}
}
