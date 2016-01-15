#include "monitor.h"
int kmain(struct multiboot *mboot_ptr)
{
   monitor_clear();
   monitor_write("Hello Kernel");
   return 0xDEADBABA;
} 

