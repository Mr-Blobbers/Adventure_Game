#include <stdio.h>
#include <string.h>
#include "headers\player.h"
#include "headers\class.h"

void save_game(const char *scene_id) {
    FILE *f = fopen("save.txt", "w");
    if (!f) return;
    fprintf(f, "%s\n", scene_id);
    fprintf(f, "%s %d %d %d %d %d %d %d %d %d %d\n",
        player.name, player.hp, player.max_hp, player.ac, player.atk_bonus,
        player.str, player.dex, player.wis, player.intel,
        player.spell_slots, player.cls
    );
    fclose(f);
    printf("Game saved.\n");
}

int load_game(char *scene_id) {
    FILE *f = fopen("save.txt", "r");
    if (!f) return 0;

    if (!fgets(scene_id, 64, f)) { fclose(f); return 0; }
    scene_id[strcspn(scene_id, "\n")] = 0;  // strip newline

    fscanf(f, "%31s %d %d %d %d %d %d %d %d %d %d",
        player.name, &player.hp, &player.max_hp, &player.ac, &player.atk_bonus,
        &player.str, &player.dex, &player.wis, &player.intel,
        &player.spell_slots, (int*)&player.cls
    );

    fclose(f);
    return 1;
}
