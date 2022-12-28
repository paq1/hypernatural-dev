#ifndef __SCENE_CABANE_H__
#define __SCENE_CABANE_H__

#include <SDL2/SDL.h>
#include "../../../core/sdd/list/list.h"

typedef struct {
    char* title;
    // todo : mettre les elements de la cabane ici


} scene_cabane_t;

scene_cabane_t* create_scene_cabane(SDL_Renderer* renderer);
void update_scene_cabane(scene_cabane_t* scene_cabane, list_t* events, double dt);
void draw_scene_cabane(scene_cabane_t* scene_cabane, SDL_Renderer* renderer);

void free_scene_cabane(scene_cabane_t** scene_cabane);

#endif // __SCENE_CABANE_H__