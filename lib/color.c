/*
*
* color.c | VGA Color Codes for the terminal
* (c) The Lennox Project & Copy05 2023
*
*/

#include <Lennox/terminal.h>

void displayAllColors(){
        for(int i = 0; i < 256; i++)
                printt("0", i);
}
