#include <stdio.h>
#include <string.h>
#include "headers\player.h"
#include "headers\class.h"

/*
This is the save/load function, saving the player name, stats and current scene ID.
*/

void save_game(const char *scene_id) { 
    FILE *f = fopen("save.txt", "w"); //Opening the save state file save.txt, if it doesn't exist, it will be created.
    if (!f) return; //If file doesn't exist and can't be created, the programm terminates
    fprintf(f, "%s\n", scene_id); //The scene ID gets written into the file
    fprintf(f, "%s %d %d %d %d %d %d %d %d %d %d\n", //Here the player data gets written into the file
        player.name, player.hp, player.max_hp, player.ac, player.atk_bonus,
        player.str, player.dex, player.wis, player.intel,
        player.spell_slots, player.cls
    );
    fclose(f); //Closing the text file
    printf("Game saved.\n"); //Telling the player that the game was saved successfully
}

int load_game(char *scene_id) {
    FILE *f = fopen("save.txt", "r"); //Opening the file in read mode
    if (!f) return 0; //If the file doesn't exist the function terminates

    if (!fgets(scene_id, 64, f)) { fclose(f); return 0; } //If the file doesn't contain a valid scene ID the function terminates and the file gets closed
    scene_id[strcspn(scene_id, "\n")] = 0;  //The scene ID gets read out and given into the current scene ID 

    fscanf(f, "%31s %d %d %d %d %d %d %d %d %d %d", //Reading (Loading) the saved player name and stats, like current HP, left over spell slots
        player.name, &player.hp, &player.max_hp, &player.ac, &player.atk_bonus,
        &player.str, &player.dex, &player.wis, &player.intel,
        &player.spell_slots, (int*)&player.cls
    );

    fclose(f); //Closing the file after successful load
    return 1;
}
