#include <common.h>
int kmain(struct multiboot *mboot_ptr)
{
   monitor_clear();
   monitor_write("Hello World!");
   return 0xDEADBABA;
} 

