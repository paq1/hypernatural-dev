#ifndef __SCENE_MENU_H__
#define __SCENE_MENU_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "../../../core/sdd/list/list.h"
#include "../../services/text_service.h"

typedef struct {
    char* title;
    // todo : mettre les elements du menu ici
    text_t* text_titre;
    double x_test;
} scene_menu_t;


scene_menu_t* create_scene_menu(SDL_Renderer* renderer);
void update_scene_menu(scene_menu_t* scene_menu, list_t* events, double dt); // todo : d'autre params pourront etre ajouté par la suite
void draw_scene_menu(scene_menu_t* scene_menu, SDL_Renderer* renderer); // todo : d'autre params pourront etre ajouté par la suite

void free_scene_menu(scene_menu_t** scene_menu);

#endif // __SCENE_MENU_H__