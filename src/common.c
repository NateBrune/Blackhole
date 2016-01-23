// common.c -- Defines some global functions.
//             From JamesM's kernel development tutorials.

#include <common.h>
#include <monitor.h>

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

void memset (void *dest, char val, unsigned int len)
{
    char *p = (char *) dest;
    for (; len != 0; --len) *p++ = val;
}

void memcpy (void *dest, const void *src, unsigned int len)
{
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    for(; len != 0; len--) *dp++ = *sp++;
}

int strlen (char *s)
{
    int i = 0;
    while (*s++) i++;
    return i;
}

int strcmp (char *str1, char *str2)
{
    while (*str1 != 0 && *str2 != 0)
    {
        if (*str1 != *str2)
        {
            return str1 - str2;
        }

        str1++; str2++;
    }

    return 0;
}

char *strcpy (char *dest, const char *src)
{
    do {
        *dest++ = *src++;
    } while (*src != 0);
    return dest;
}

char *strncpy (char *dst, char *src, int n)
{
    int i = 0;
    while (n--)
    {
        dst[i] = src[i];
        i++;
    }

    return dst;
}
extern void panic(char *message, char *file, u32int line)
{
    // We encountered a massive problem and have to stop.
    __asm volatile("cli"); // Disable interrupts.

    monitor_write("PANIC(", red);
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
