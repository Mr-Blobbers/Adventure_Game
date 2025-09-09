#include "headers\common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int roll_dice(int n, int sides) {
    int total = 0;
    for (int i = 0; i < n; i++) total += (rand() % sides) + 1;
    return total;
}

int clampi(int v, int lo, int hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

int stat_mod(int stat) {
    return (stat - 10) / 2;
}

void read_line(char *buf, size_t n) {
    if (!fgets(buf, (int)n, stdin)) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = 0;
}

int read_int() {
    char buf[64];
    read_line(buf, sizeof(buf));
    return atoi(buf);
}
