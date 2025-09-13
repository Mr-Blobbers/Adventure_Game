#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers\engine.h"
#include "headers\player.h"

int main(){
    srand((unsigned)time(NULL)); //Initializing the randomizer for the dice rolls.
    init_new_player(); //Initializin the new player
    run_game(); //Running the game
    return 0;
}
