#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers\engine.h"
#include "headers\player.h"

int main(){
    srand((unsigned)time(NULL));
    init_new_player();
    run_game();
    return 0;
}
