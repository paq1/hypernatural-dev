#include "scene_menu.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "../../enums/events_enum.h"
#include "../../factories/font_factory.h"

scene_menu_t* create_scene_menu(SDL_Renderer* renderer) {
    scene_menu_t* scene_menu = (scene_menu_t*) malloc(sizeof(scene_menu_t));
    SDL_Color color = { 255, 255, 255 };
    text_t* text_titre = create_text(renderer, "Hypernatural", 800 / 2 - 50, 0, get_font_factory()->main_font, color);
    *scene_menu = (scene_menu_t) { "Menu", text_titre };

    return scene_menu;
}

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
    draw_text(scene_menu->text_titre, renderer);
}

void free_scene_menu(scene_menu_t** scene_menu) {
    free_text(&(*scene_menu)->text_titre);
    free(*scene_menu);
    *scene_menu = NULL;
}