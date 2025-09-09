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
    char scene_id[64] = "start";
    printf("Load saved game? (y/n) ");
    char buf[16]; read_line(buf, sizeof(buf));
    if(buf[0]=='y'||buf[0]=='Y') {
        if(!load_game(scene_id)) printf("No save found, starting new.\n");
    }

    while(1) {
        Scene *s = find_scene(scene_id);
        if(!s) { printf("Scene not found!\n"); break; }

        printf("\n--- %s ---\n%s\n", s->id, s->text);

        if(s->heal>0) {
            player.hp = clampi(player.hp+s->heal,0,player.max_hp);
            printf("You heal %d. HP now %d\n", s->heal, player.hp);
        }

        if(s->encounter) {
            Encounter e=*s->encounter;
            int r=combat_encounter(&e);
            if(r<0) break; // died
        }

        if(s->n_choices==0) break;
        for(int i=0;i<s->n_choices;i++)
            printf("[%d] %s\n",i+1,s->choices[i].text);
        printf("[S]ave\n> ");

        char choice[16]; read_line(choice,sizeof(choice));
        if(choice[0]=='S'||choice[0]=='s'){ save_game(scene_id); continue; }
        int pick=atoi(choice);
        if(pick<1||pick> s->n_choices) pick=1;
        strcpy(scene_id, s->choices[pick-1].target_id);
    }
    printf("Game over.\n");
}
