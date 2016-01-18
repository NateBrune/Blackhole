#include "monitor.h"
#include "descriptor_tables.h"
#include "common.h"
#include "isr.h"
#include "timer.h"
int kmain(struct multiboot *mboot_ptr)
{
    monitor_clear();
    monitor_write("\n\n", white);
    monitor_write_center("Welcome to ImperitOS\n\n\n", white);
    monitor_write("Initializing descriptors... ", white); init_descriptor_tables(); monitor_put('[',white); monitor_write("ok", green); monitor_write("]\n",white);
    monitor_write("Initializing PIT... ", white); init_timer(100); monitor_put('[',white);monitor_write("ok", green);monitor_write("]\n",white); 
    return 0;
}
