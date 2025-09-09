#ifndef PLAYER_H
#define PLAYER_H
#include "class.h"

typedef struct {
    char name[32];
    int hp, max_hp;
    int ac;
    int atk_bonus;
    int str, dex, wis, intel;
    int spell_slots;
    ClassType cls;
} Player;

extern Player player;

void init_new_player();
void setup_class_defaults(ClassType c);

#endif
