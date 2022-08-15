#ifndef __SCENE_HANDLER_H__
#define __SCENE_HANDLER_H__

#include "../enums/scene_enum.h"
#include "scene_menu/scene_menu.h"


typedef struct {
    enum scene_enum current_scene;
    // todo : ajouter les scenes ici
    scene_menu_t* scene_menu;
} scene_handler_t;

scene_handler_t* create_scene_handler();
void handle_scenes(scene_handler_t* scene_handler);
void free_scene_handler(scene_handler_t** scene_handler);

#endif // __SCENE_HANDLER_H__
