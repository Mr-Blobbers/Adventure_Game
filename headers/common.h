#ifndef COMMON_H
#define COMMON_H
#include <stddef.h>

int roll_dice(int n, int sides);
int clampi(int v, int lo, int hi);
int stat_mod(int stat);
void read_line(char *buf, size_t n);
int read_int();

#endif
