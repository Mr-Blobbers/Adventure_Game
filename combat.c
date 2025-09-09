#include <stdio.h>
#include "headers\combat.h"
#include "headers\player.h"
#include "headers\common.h"

int combat_encounter(Encounter *e) {
    printf("Combat starts: %s appears!\n", e->name);
    while(player.hp > 0 && e->hp > 0) {
        printf("\n%s HP %d/%d | %s HP %d\n", player.name, player.hp, player.max_hp, e->name, e->hp);
        printf("Choose action: [A]ttack [H]eal [R]un\n> ");
        char choice[16]; read_line(choice, sizeof(choice));
        if(choice[0]=='A'||choice[0]=='a') {
            int roll = roll_dice(1,20) + player.atk_bonus + stat_mod(player.str);
            if(roll >= e->ac) {
                int dmg = roll_dice(1,6) + stat_mod(player.str);
                if(dmg<1) dmg=1;
                e->hp -= dmg;
                printf("You hit for %d!\n", dmg);
            } else printf("You miss!\n");
        } else if(choice[0]=='H'||choice[0]=='h') {
            int heal = roll_dice(1,8) + stat_mod(player.wis);
            player.hp = clampi(player.hp+heal, 0, player.max_hp);
            printf("You heal %d. HP now %d\n", heal, player.hp);
        } else if(choice[0]=='R'||choice[0]=='r') {
            printf("You run away!\n");
            return 0;
        }

        if(e->hp > 0) {
            int roll = roll_dice(1,20) + e->atk;
            if(roll >= player.ac) {
                int dmg = roll_dice(1, e->dmg_die);
                player.hp -= dmg;
                printf("%s hits you for %d!\n", e->name, dmg);
            } else printf("%s misses!\n", e->name);
        }
    }
    if(player.hp <= 0) { printf("You were slain!\n"); return -1; }
    printf("You defeated %s!\n", e->name);
    return 1;
}
