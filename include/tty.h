#include "common.h"

static void move_cursor();
static void scroll();
static void monitor_put(char character);
void monitor_clear();
void monitor_write(char *string);
