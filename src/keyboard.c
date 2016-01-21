#include "keyboard.h"
#include "isr.h"
#include "monitor.h"

static void key_callback(registers_t *regs)
{
    unsigned char c = inb(0x60);
    if(!(c & 0x80))
    {
      unsigned char key = kbdus[c];
      if(key == '\b'){
        monitor_put(key, white);
        monitor_write("  ", white);
        monitor_put(key, white);
      }
	    monitor_put(key, white); 
    }
}
void init_keyboard()
{
    register_interrupt_handler(33, &key_callback);
}

