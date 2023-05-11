#include "stdlib.h"
#include "../terminal/terminal.h"
#include "../utils/color.h"

u32 strlen(const char* str){
	u32 len = 0;
	while(str[len]){
		len++;
	}
	return len;
}

void *memset(void *dst, char c, u32 n){
	char *temp = dst;
	for(; n != 0; n--) *temp++ = c;
	return dst;
}

