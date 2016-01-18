// monitor.h -- Defines the interface for monitor.h
//              From JamesM's kernel development tutorials.

#ifndef MONITOR_H
#define MONITOR_H

#include "common.h"

#define black          0
#define blue           1
#define green          2
#define cyan           3
#define red            4
#define magenta        5
#define brown          6
#define lightgray      7
#define darkgrey       8
#define lightblue      9
#define lightgreen    10
#define lightcyan     11
#define lightred      12
#define lightmagenta  13
#define yellow        14
#define white         15

// Write a single character out to the screen.
void monitor_put(char c, u8int color);

// Clear the screen to all black.
void monitor_clear();

// Output a null-terminated ASCII string to the monitor.
void monitor_write(char *c, u8int color);

// Output a null-terminated hexadecimal interger to the monitor.
void monitor_write_hex(u32int n, u8int color);

// Output a null-terminated decimal interger to the monitor
void monitor_write_dec(u32int n, u8int color);

#endif // MONITOR_H
