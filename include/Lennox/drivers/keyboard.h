/*
*
* keyboard.h | The Keyboard Driver
* (c) The Lennox Project & Copy05 2023
*
*/

#include <Lennox/ctypes.h>

#define KEYBOARD_PORT 0x60

extern char buffer[256];
extern u32 buf_pos;

void keyboard_handler();
