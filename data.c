#include "headers\scene.h"
#include <stddef.h>  // for NULL
/* Different Enemy Encounters */
Encounter goblin = {"Goblin", 6, 12, 3, 6};
Encounter orc    = {"Orc",    12, 13, 4, 8};

//The available scenes including the enemy encounter
Scene scenes[] = {
    { "start", "You stand at the entrance of a dungeon.", 0, NULL, 2,
      { {"Enter", "hall"}, {"Leave", "exit"}, {"", ""}, {"", ""} } },
    { "hall", "You are in a hallway. A goblin jumps out!", 0, &goblin, 1,
      { {"Continue", "after_goblin"}, {"", ""}, {"", ""}, {"", ""} } },
    { "after_goblin", "The goblin lies dead. A door lies ahead.", 0, NULL, 2,
      { {"Open", "treasure"}, {"Exit", "exit"}, {"", ""}, {"", ""} } },
    { "treasure", "You find a chest of gold!", 0, &orc, 1,
      { {"Exit", "exit"}, {"", ""}, {"", ""}, {"", ""} } },
    { "exit", "You leave the dungeon. The adventure ends.", 0, NULL, 0,
      { {"", ""}, {"", ""}, {"", ""}, {"", ""} } }
};
int scene_count = sizeof(scenes)/sizeof(scenes[0]);
