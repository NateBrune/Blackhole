#ifndef TIMER_H
#define TIMER_H

#include "common.h"

void init_keyboard();

unsigned char kbdus[127] =
{
    -1,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '8', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 18 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    -1,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 38 */
 '\'', '`',   -1,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 48 */
  'm', ',', '.', '/',   -1,				/* Right shift */
  '*',
    -1,	/* Alt */
  ' ',	/* Space bar */
    -1,	/* Caps lock */
    -1,	/* 59 - F1 key ... > */
    -1,   0,   0,   0,   0,   0,   0,   0,
    -1,	/* < ... F10 */
    -1,	/* 69 - Num lock*/
    -1,	/* Scroll Lock */
    -1,	/* Home key */
    -1,	/* Up Arrow */
    -1,	/* Page Up */
  '-',
    -1,	/* Left Arrow */
    -1,
    -1,	/* Right Arrow */
  '+',
    -1,	/* 79 - End key*/
    -1,	/* Down Arrow */
    -1,	/* Page Down */
    -1,	/* Insert Key */
    -1,	/* Delete Key */
    -1,   0,   0,
    -1,	/* F11 Key */
    -1,	/* F12 Key */
    -1,	/* All other keys are undefined */
};

#endif
