#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers\engine.h"
#include "headers\scene.h"
#include "headers\combat.h"
#include "headers\player.h"
#include "headers\save.h"
#include "headers\common.h"

void run_game() { 
    char scene_id[64] = "start"; //Starting the game 
    printf("Load saved game? (y/n) "); //Check if the player wants to load a save
    char buf[16]; read_line(buf, sizeof(buf)); //Read the player input
    if(buf[0]=='y'||buf[0]=='Y') { //Check if the input was 'Y' or 'y'
        if(!load_game(scene_id)) printf("No save found, starting new.\n"); //If no safe of that user is found, a new game will be started.
    }
    //Following are re-declarations of the functions for the engine
    while(1) {
        Scene *s = find_scene(scene_id); //Getting the current scene
        if(!s) { printf("Scene not found!\n"); break; } //Error case if the corrosponding scene wasn't found

        printf("\n--- %s ---\n%s\n", s->id, s->text); //Output of the scene and it's sub text

        if(s->heal>0) { //If the option [H]eal was picket
            player.hp = clampi(player.hp+s->heal,0,player.max_hp); //New player HP is current HP + heal
            printf("You heal %d. HP now %d\n", s->heal, player.hp); //Telling the player for how much they have healed
        }

        if(s->encounter) { //Grabbing the corrosponding encounter to the scene
            Encounter e=*s->encounter;
            int r=combat_encounter(&e); //If encounter was found, enter combat
            if(r<0) break; //If no encounter was found, move forward
        }
        //This is the safe function, where the player gets asked if they want to [S]ave the game.
        if(s->n_choices==0) break; 
        for(int i=0;i<s->n_choices;i++)
            printf("[%d] %s\n",i+1,s->choices[i].text);
        printf("[S]ave\n> ");

        char choice[16]; read_line(choice,sizeof(choice)); //Reading the player input
        if(choice[0]=='S'||choice[0]=='s'){ save_game(scene_id); continue; } //If input was 'S' or 's', save the game and continue
        int pick=atoi(choice);
        if(pick<1||pick> s->n_choices) pick=1;
        strcpy(scene_id, s->choices[pick-1].target_id);
    }
    printf("Game over.\n"); //Game Over message after finishing the game
}
