#include "monitor.h"
#include "descriptor_tables.h"
#include "common.h"
#include "isr.h"

static void calla(registers_t regs)
{
  monitor_write("I got this shit handled: ");
  monitor_write_dec(regs.int_no);
  monitor_write("\n");
  return;
}

int kmain(struct multiboot *mboot_ptr)
{
   init_descriptor_tables();
   monitor_clear();
   monitor_write("Hello Kernel \n");
   register_interrupt_handler(3, &calla);
   asm volatile ("int $0x8");
   while(1){}
   return 0;
}
