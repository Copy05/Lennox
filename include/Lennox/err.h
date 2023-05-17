/*
*
* err.h | Error handling
* (c) The Lennox Project & Copy05 2023
*
*/

#include <Lennox/terminal.h>

// thanks gcc...
void __stack_chk_fail_local(){
        printt("[ERROR] ", BRIGHT_RED);
        printt("__stack_chk_fail_local() has been called", WHITE);
        newline();
}
