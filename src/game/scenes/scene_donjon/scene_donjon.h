#ifndef __SCENE_DONJON_H__
#define __SCENE_DONJON_H__

#include <SDL2/SDL.h>

#include "../../../core/sdd/list/list.h"

#include "tilemap/tilemap.h"

typedef struct {
    char* title;

    tilemap_t* tilemap;
    // todo : mettre les elements du donjon ici

} scene_donjon_t;

scene_donjon_t* create_scene_donjon(SDL_Renderer* renderer);
void update_scene_donjon(scene_donjon_t* scene_donjon, list_t* events, double dt); // todo : d'autre params pourront etre ajouté par la suite
void draw_scene_donjon(scene_donjon_t* scene_donjon, SDL_Renderer* renderer); // todo : d'autre params pourront etre ajouté par la suite

void free_scene_donjon(scene_donjon_t** scene_donjon);
#endif // __SCENE_DONJON_H__