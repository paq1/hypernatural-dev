#include "scene_cabane.h"

#include "../../enums/events_enum.h"

scene_cabane_t* create_scene_cabane(SDL_Renderer* renderer) {
    scene_cabane_t* scene_cabane = (scene_cabane_t*) malloc(sizeof(scene_cabane_t));
    *scene_cabane = (scene_cabane_t) { "Cabane" };
    // todo : initialiser les elements de la cabane ici
    return scene_cabane;
}
void update_scene_cabane(scene_cabane_t* scene_cabane, list_t* events) {
    while (events) {
        enum event_enum event = *((enum event_enum*)(events->data));
        //todo ajouter les evenements si on en a
        events = events->next;
    }
}
void draw_scene_cabane(scene_cabane_t* scene_cabane, SDL_Renderer* renderer) {
    // todo afficher ce qu'on a afficher
}

void free_scene_cabane(scene_cabane_t** scene_cabane) {
    free(*scene_cabane);
    *scene_cabane = NULL;
}