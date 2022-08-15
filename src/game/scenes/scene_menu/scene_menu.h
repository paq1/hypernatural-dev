#ifndef __SCENE_MENU_H__
#define __SCENE_MENU_H__

#include <SDL2/SDL.h>

#include "../../../core/sdd/list/list.h"

typedef struct {
    char* title;
    // todo : mettre les elements du menu ici
} scene_menu_t;

void update_scene_menu(scene_menu_t* scene_menu, list_t* events); // todo : d'autre params pourront etre ajouté par la suite
void draw_scene_menu(scene_menu_t* scene_menu, SDL_Renderer* renderer); // todo : d'autre params pourront etre ajouté par la suite

#endif // __SCENE_MENU_H__