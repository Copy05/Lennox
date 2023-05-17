#include <Lennox/asm.h>
#include <Lennox/basics.h>

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
