#include <stdio.h>
#include "headers\combat.h" 
#include "headers\player.h"
#include "headers\common.h"

int combat_encounter(Encounter *e) {  //Depending on the current path an encounter gets chosen and cast into the function
    printf("Combat starts: %s appears!\n", e->name); //Combat message incl. enemy name
    while(player.hp > 0 && e->hp > 0) { //While loop to check if player and the enemy has HP left
        printf("\n%s HP %d/%d | %s HP %d\n", player.name, player.hp, player.max_hp, e->name, e->hp); //Player HUD and Enemy information
        printf("Choose action: [A]ttack [H]eal [R]un\n> "); //Player choice between [A]ttack, self [H]eal and [R]unning away
        char choice[16]; read_line(choice, sizeof(choice)); 
        if(choice[0]=='A'||choice[0]=='a') { //If the choice was attack
            int roll = roll_dice(1,20) + player.atk_bonus + stat_mod(player.str); //Attack roll, 1d20 + player attack bonus (class dependant) + strength bonus (class dependant)
            if(roll >= e->ac) { //If the damage roll is bigger than enemies armor class
                int dmg = roll_dice(1,6) + stat_mod(player.str); //Then roll another d6 of damage
                if(dmg<1) dmg=1; //If damage dealt would be smaller than 1, deal 1 damage
                e->hp -= dmg; //Enemy HP minues damage
                printf("You hit for %d!\n", dmg); //Print for damage done by the player
            } else printf("You miss!\n"); // If the attack missed
        } else if(choice[0]=='H'||choice[0]=='h') { //If choise was Heal
            int heal = roll_dice(1,8) + stat_mod(player.wis); // Roll 1 d8 plus wisdom modifier
            player.hp = clampi(player.hp+heal, 0, player.max_hp); //Adding the heal roll to players current HP
            printf("You heal %d. HP now %d\n", heal, player.hp); //Print for the successful heal
        } else if(choice[0]=='R'||choice[0]=='r') { //If you chose the coward option
            printf("You run away!\n"); //You got away *slow clap*
            return 0;
        }

        if(e->hp > 0) { //Checking if enemy has HP left
            int roll = roll_dice(1,20) + e->atk; //Enemy rolls a d20 for damage as well
            if(roll >= player.ac) { //Enemies attack roll comparison to Player armor class
                int dmg = roll_dice(1, e->dmg_die); //Casting the damage roll into the integer 'dmg'
                player.hp -= dmg; //Subtracting the enemy damage from Player HP
                printf("%s hits you for %d!\n", e->name, dmg); //Print for enemy damage
            } else printf("%s misses!\n", e->name); //Print for enemy's missed attack
        }
    }
    if(player.hp <= 0) { printf("You were slain!\n"); return -1; } //If player health drops to 0
    printf("You defeated %s!\n", e->name); //Defeat message
    return 1;
}
