#include "../../basics.h"
#include "keyboard.h"

u8 inb(u16 port)
{
  u8 ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
  return ret;
}

void outb(u16 port, u8 data)
{
  asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
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
	char character = 0;
	char keycode = 0;

	do {
		keycode = getkeycode();
		if(keycode == KEY_ENTER)
			newline();
		else
			printchar(character);
		_sleep(0x02FFFFFF);
	} while (character > 0);
}
