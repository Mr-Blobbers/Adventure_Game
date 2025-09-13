#include <string.h>
#include "headers\scene.h"

Scene* find_scene(const char *id) { //Picking the scene depending on the scene ID
    for(int i=0;i<scene_count;i++) if(strcmp(scenes[i].id,id)==0) return &scenes[i]; //Rolling over to the next scene by tacking the scene ID +1
    return NULL;
}
