//
// isr.c -- High level interrupt service routines and interrupt request handlers.
//          Part of this code is modified from Bran's kernel development tutorials.
//          Rewritten for JamesM's kernel development tutorials.
//

#include <common.h>
#include <isr.h>
#include <monitor.h>

isr_t interrupt_handlers[256];

void register_interrupt_handler(u8int n, isr_t handler)
{
    interrupt_handlers[n] = handler;
}

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t *regs)
{
    if(interrupt_handlers[regs->int_no])
    {
        isr_t fun = interrupt_handlers[regs->int_no];
        fun(regs);
        outb(0xa0, 0x20); // for pic1
        outb(0x20, 0x20);  // for pic
        return;
    }
    monitor_write("recieved unregistered interrupt: ", white);  // only for unregistered interrupts.
    monitor_write_dec(regs->int_no, red);
    monitor_put('\n',white);
    outb(0xa0, 0x20); // for pic1
    outb(0x20, 0x20);  // for pic
}
