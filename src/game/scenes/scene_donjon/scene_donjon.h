#ifndef __SCENE_DONJON_H__
#define __SCENE_DONJON_H__

#include <stdbool.h>
#include <SDL2/SDL.h>

#include "../../../core/sdd/list/list.h"

#include "tilemap/tilemap.h"
#include "../../models/camera/camera.h"
#include "../../services/text_service.h"

typedef struct {
    char* title;

    tilemap_t* tilemap;
    camera_t camera;
    text_t* pos_camera_text;

    bool right_pressed, left_pressed, up_pressed, down_pressed;
    // todo : mettre les elements du donjon ici

} scene_donjon_t;

scene_donjon_t* create_scene_donjon(SDL_Renderer* renderer);
void update_scene_donjon(scene_donjon_t* scene_donjon, list_t* events, double dt, SDL_Renderer* renderer); // todo : d'autre params pourront etre ajouté par la suite
void draw_scene_donjon(scene_donjon_t* scene_donjon, SDL_Renderer* renderer); // todo : d'autre params pourront etre ajouté par la suite

void free_scene_donjon(scene_donjon_t** scene_donjon);
#endif // __SCENE_DONJON_H__