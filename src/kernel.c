#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "paging.h"
#include "keyboard.h"

int kmain(struct multiboot *mboot_ptr)
{
    monitor_clear();
    monitor_write("\n\n", white);
    monitor_write_center("Welcome to ImperitOS\n\n\n", white);
    monitor_write("Initializing descriptors... ", white); init_descriptor_tables(); monitor_write("ok\n", green);
    monitor_write("Initializing PIT... ", white); init_timer(100); monitor_write("ok\n", green);
    monitor_write("Initializing paging... ", white); init_paging(); monitor_write("ok\n", green);
    monitor_write("Initializing keyboard... ", white); init_keyboard(); monitor_write("ok\n", green);
    u32int a = kmalloc(8);	
    u32int b = kmalloc(8);
    u32int c = kmalloc(8);
    monitor_write("a: ", white);
    monitor_write_hex(a);
    monitor_write(", b: ", white);
    monitor_write_hex(b);
    monitor_write("\nc: ", white);
    monitor_write_hex(c);
    kfree(c);
    kfree(b);
    u32int d = kmalloc(16);
    monitor_write(", d: ", white);
    monitor_write_hex(d); 
    for(;;);
    return 0;
}
