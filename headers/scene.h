#ifndef SCENE_H
#define SCENE_H
#include "combat.h"

typedef struct {
    const char *text;
    const char *target_id;
} Choice;

typedef struct {
    const char *id;
    const char *text;
    int heal;
    Encounter *encounter;
    int n_choices;
    Choice choices[4];
} Scene;

extern Scene scenes[];
extern int scene_count;

Scene* find_scene(const char *id);

#endif
