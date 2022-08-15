#ifndef __SCENE_DONJON_H__
#define __SCENE_DONJON_H__

#include "../../../core/sdd/list/list.h"

typedef struct {
    char* title;
    // todo : mettre les elements du donjon ici
} scene_donjon_t;

void update_scene_donjon(scene_donjon_t* scene_donjon, list_t* events); // todo : d'autre params pourront etre ajouté par la suite
void draw_scene_donjon(scene_donjon_t* scene_donjon); // todo : d'autre params pourront etre ajouté par la suite

#endif // __SCENE_DONJON_H__