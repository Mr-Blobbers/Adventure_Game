#include "headers\class.h"
/*Switch case to choose your class*/
const char* class_name(ClassType c) {
    switch(c) {
        case CLASS_FIGHTER: return "Fighter";
        case CLASS_RANGER: return "Ranger";
        case CLASS_WIZARD: return "Wizard";
        case CLASS_BARD: return "Bard";
        case CLASS_WARLOCK: return "Warlock";
        case CLASS_ROGUE: return "Rogue";
        case CLASS_PALADIN: return "Paladin";
        case CLASS_DRUID: return "Druid";
        case CLASS_BARBARIAN: return "Barbarian";
        case CLASS_CLERIC: return "Cleric";
        default: return "Unknown";
    }
}
