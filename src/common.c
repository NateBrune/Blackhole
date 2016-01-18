// common.c -- Defines some global functions.
// From JamesM's kernel development tutorials.

#include "common.h"

// Write a byte out to the specified port.
void outb(u16int port, u8int value)
{
    __asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

u8int inb(u16int port)
{
   u8int ret;
   __asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}

u16int inw(u16int port)
{
   u16int ret;
   __asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}

void *memset(void *s, char c, u32int n)
{
  u32int i;
  for (i = 0; i < n; ++i)
    *(char *)(s++) = c;
  return s - n;
}
