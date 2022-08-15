#include "scene_menu.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "../../enums/events_enum.h"

void update_scene_menu(scene_menu_t* scene_menu, list_t* events) {
    // todo : handle events
    // printf("INFO: nombre d'evenements : %d\n", list_length(events));

    while (events) {
        printf("INFO: evenement trouver\n");
        enum event_enum event = *((enum event_enum*)(events->data));
        if (event == SPACE_BAR_PRESSED) {
            printf("INFO: evenement SPACE_BAR_PRESSED\n");
        }
        events = events->next;
    }

    // todo : update 
    // printf("update de : %s\n", scene_menu->title);
}
void draw_scene_menu(scene_menu_t* scene_menu) {
    // printf("affiche de : %s\n", scene_menu->title);
}