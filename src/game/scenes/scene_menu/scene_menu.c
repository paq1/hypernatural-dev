#include "scene_menu.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "../../enums/events_enum.h"

void update_scene_menu(scene_menu_t* scene_menu, list_t* events) {
    while (events) {
        enum event_enum event = *((enum event_enum*)(events->data));
        if (event == SPACE_BAR_PRESSED) {
            printf("INFO: evenement SPACE_BAR_PRESSED dans le menu\n");
        }
        events = events->next;
    }
}
void draw_scene_menu(scene_menu_t* scene_menu, SDL_Renderer* renderer) {
}