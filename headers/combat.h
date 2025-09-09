#ifndef COMBAT_H
#define COMBAT_H

typedef struct {
    const char *name;
    int hp;
    int ac;
    int atk;
    int dmg_die;
} Encounter;

int combat_encounter(Encounter *e);

#endif
