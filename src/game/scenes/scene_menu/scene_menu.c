#include "scene_menu.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

void update_scene_menu(scene_menu_t* scene_menu) {
    // todo : handle events

    // todo : update 
    printf("update de : %s\n", scene_menu->title);
}
void draw_scene_menu(scene_menu_t* scene_menu) {
    printf("affiche de : %s\n", scene_menu->title);
}