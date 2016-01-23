// common.c -- Defines some global functions.
// From JamesM's kernel development tutorials.

#include "common.h"
#include "monitor.h"

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
   unsigned char* p=s;
   while(n--)
      *p++ = (unsigned char)c;
   return s; 
}

extern void panic(char *message, char *file, u32int line)
{
    // We encountered a massive problem and have to stop.
    __asm volatile("cli"); // Disable interrupts.

    monitor_write("PANIC(",red);
    monitor_write(message,red);
    monitor_write(") at ",red);
    monitor_write(file,red);
    monitor_write(":",red);
    monitor_write_dec(line,red);
    monitor_write("\n",red);
    // Halt by going into an infinite loop.
    for(;;);
}

extern void panic_assert(char *file, u32int line, char *desc)
{
    // An assertion failed, and we have to panic.
    __asm volatile("cli"); // Disable interrupts.

    monitor_write("ASSERTION-FAILED(",red);
    monitor_write(desc,red);
    monitor_write(") at ",red);
    monitor_write(file,red);
    monitor_write(":",red);
    monitor_write_dec(line,red);
    monitor_write("\n",red);
    // Halt by going into an infinite loop.
    for(;;);
}
