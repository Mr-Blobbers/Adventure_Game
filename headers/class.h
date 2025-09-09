#ifndef CLASS_H
#define CLASS_H

typedef enum {
    CLASS_FIGHTER,
    CLASS_RANGER,
    CLASS_WIZARD,
    CLASS_BARD,
    CLASS_WARLOCK,
    CLASS_ROGUE,
    CLASS_PALADIN,
    CLASS_DRUID,
    CLASS_BARBARIAN,
    CLASS_CLERIC,
    CLASS_COUNT
} ClassType;

const char* class_name(ClassType c);

#endif
