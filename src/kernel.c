#include <monitor.h>
#include <descriptor_tables.h>
#include <timer.h>
#include <paging.h>
#include <kheap.h>
#include <keyboard.h>

int kmain(struct multiboot *mboot_ptr)
{
    monitor_clear();
    monitor_write("\n\n", white);
    monitor_write_center("Welcome to the blackhole\n\n\n", white);
    monitor_write("Initializing descriptors... ", white); init_descriptor_tables(); monitor_write("ok\n", green);
    monitor_write("Initializing PIT... ", white); init_timer(100); monitor_write("ok\n", green);
    monitor_write("Initializing paging... ", white); init_paging(); monitor_write("ok\n", green);
    monitor_write("Initializing keyboard... ", white); init_keyboard(); monitor_write("ok\n", green);
    return 0;
}
