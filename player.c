#include <stdio.h>
#include <string.h>
#include "headers\player.h"
#include "headers\class.h"
#include "headers\common.h"

Player player;

void setup_class_defaults(ClassType c) {
    player.cls = c;
    player.spell_slots = 0;
    switch(c) {
        case CLASS_FIGHTER:   player.max_hp=16; player.ac=16; player.atk_bonus=3; player.str=16; player.dex=12; player.wis=10; player.intel=10; break;
        case CLASS_RANGER:    player.max_hp=10; player.ac=12; player.atk_bonus=3; player.str=6;  player.dex=16; player.wis=12; player.intel=14; player.spell_slots=2; break;
        case CLASS_WIZARD:    player.max_hp=10; player.ac=12; player.atk_bonus=1; player.str=8;  player.dex=12; player.wis=12; player.intel=16; player.spell_slots=3; break;
        case CLASS_BARD:      player.max_hp=12; player.ac=13; player.atk_bonus=2; player.str=10; player.dex=14; player.wis=12; player.intel=12; player.spell_slots=2; break;
        case CLASS_WARLOCK:   player.max_hp=12; player.ac=13; player.atk_bonus=2; player.str=10; player.dex=12; player.wis=10; player.intel=14; player.spell_slots=2; break;
        case CLASS_ROGUE:     player.max_hp=12; player.ac=14; player.atk_bonus=2; player.str=12; player.dex=16; player.wis=10; player.intel=12; break;
        case CLASS_PALADIN:   player.max_hp=14; player.ac=16; player.atk_bonus=2; player.str=16; player.dex=10; player.wis=12; player.intel=10; player.spell_slots=2; break;
        case CLASS_DRUID:     player.max_hp=12; player.ac=13; player.atk_bonus=1; player.str=10; player.dex=12; player.wis=16; player.intel=12; player.spell_slots=3; break;
        case CLASS_BARBARIAN: player.max_hp=18; player.ac=14; player.atk_bonus=3; player.str=16; player.dex=12; player.wis=10; player.intel=8; break;
        case CLASS_CLERIC:    player.max_hp=14; player.ac=15; player.atk_bonus=2; player.str=12; player.dex=10; player.wis=16; player.intel=10; player.spell_slots=3; break;
        default: break;
    }
    player.hp = player.max_hp;
}

void init_new_player() {
    printf("Enter your name: ");
    read_line(player.name, sizeof(player.name));
    if(strlen(player.name)==0) strcpy(player.name, "Adventurer");

    printf("Choose your class:\n");
    for(int i=0;i<CLASS_COUNT;++i) printf("[%d] %s\n", i+1, class_name(i));
    printf("> ");
    int pick = read_int();
    if(pick<1 || pick>CLASS_COUNT) pick=1;
    setup_class_defaults((ClassType)(pick-1));
    printf("Welcome, %s the %s! HP %d AC %d\n", player.name, class_name(player.cls), player.hp, player.ac);
}
