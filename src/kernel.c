#include "monitor.h"
#include "descriptor_tables.h"
#include "common.h"
#include "isr.h"

int kmain(struct multiboot *mboot_ptr)
{
   init_descriptor_tables();
   monitor_clear();
   monitor_write("Hello Kernel \n");
   asm volatile ("int $0x2");
   asm volatile ("int $0x3");
   return 0;
}
