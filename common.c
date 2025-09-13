#include "headers\common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int roll_dice(int n, int sides) { //The function for the dice roll
    int total = 0;
    for (int i = 0; i < n; i++) total += (rand() % sides) + 1; //Rolling the dice with the max total depending on how many sides the dice has.
    return total;
}

int clampi(int v, int lo, int hi) { 
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

int stat_mod(int stat) {
    return (stat - 10) / 2; //Calculation for the stat bonusses for examble a character with 18 strength gets 18 - 10 / 2 bonus on their attack, or wisdom - 10 / 2 on their heals etc
}

void read_line(char *buf, size_t n) { //Function to read the the save file
    if (!fgets(buf, (int)n, stdin)) { //Terminating the function if no lines got found
        buf[0] = '\0'; //Setting the buffer back to 0
        return;
    }
    buf[strcspn(buf, "\n")] = 0; 
}

int read_int() {
    char buf[64];
    read_line(buf, sizeof(buf));
    return atoi(buf);
}
