#include "scene_donjon.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "../../enums/events_enum.h"

scene_donjon_t* create_scene_donjon(SDL_Renderer* renderer) {
    scene_donjon_t* scene_donjon = malloc(sizeof(scene_donjon_t));
    *scene_donjon = (scene_donjon_t) {"Donjon"};
    return scene_donjon;
}
void update_scene_donjon(scene_donjon_t* scene_donjon, list_t* events, double dt) {
    
    while (events) {
        enum event_enum event = *((enum event_enum*)(events->data));
        if (event == SPACE_BAR_PRESSED) {
            printf("INFO: evenement SPACE_BAR_PRESSED dans le donjon\n");
        }
        events = events->next;
    }
}
void draw_scene_donjon(scene_donjon_t* scene_donjon, SDL_Renderer* renderer) {
}

void free_scene_donjon(scene_donjon_t** scene_donjon) {
    free(*scene_donjon);
    *scene_donjon = NULL;
}