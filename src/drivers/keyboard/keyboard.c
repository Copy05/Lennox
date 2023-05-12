/*
*
* Keyboard.c | The keyboard driver
* (c) The Lennox Project & Copy05 2023
*
*/


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
	char c = 0;
	
	c = inb(KEYBOARD_PORT);
	do {
		if(c > 0){
			printchar(c);
		}
	} while (c != 1);
}
