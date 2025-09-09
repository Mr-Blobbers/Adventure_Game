#include <string.h>
#include "headers\scene.h"

Scene* find_scene(const char *id) {
    for(int i=0;i<scene_count;i++) if(strcmp(scenes[i].id,id)==0) return &scenes[i];
    return NULL;
}
