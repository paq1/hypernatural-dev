#include "scene_menu.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "../../enums/events_enum.h"
#include "../../factories/font_factory.h"
#include "../../factories/sprite_factory.h"
#include "../../services/draw_sprite_service.h"

scene_menu_t* create_scene_menu(SDL_Renderer* renderer) {
    scene_menu_t* scene_menu = (scene_menu_t*) malloc(sizeof(scene_menu_t));
    SDL_Color color = { 255, 255, 255 };
    text_t* text_titre = create_text(renderer, "Hypernatural", 800 / 2 - 50, 0, get_font_factory()->main_font, color);
    *scene_menu = (scene_menu_t) { "Menu", text_titre, 0.0 };

    return scene_menu;
}

void update_scene_menu(scene_menu_t* scene_menu, list_t* events, double dt) {
    while (events) {
        enum event_enum event = *((enum event_enum*)(events->data));
        if (event == SPACE_BAR_PRESSED) {
            printf("INFO: evenement SPACE_BAR_PRESSED dans le menu\n");
        }
        events = events->next;
    }

    // todo : c'est juste un test (a supprimer)
    scene_menu->x_test += 50 * dt;
    if (scene_menu->x_test > 700) {
        scene_menu->x_test = 0;
    }

}
void draw_scene_menu(scene_menu_t* scene_menu, SDL_Renderer* renderer) {
    draw_text(scene_menu->text_titre, renderer);
    draw_sprite_with_scale(get_sprite_factory(renderer)->sprite_test, renderer, scene_menu->x_test, 200, 4.0, 4.0);
}

void free_scene_menu(scene_menu_t** scene_menu) {
    free_text(&(*scene_menu)->text_titre);
    free(*scene_menu);
    *scene_menu = NULL;
}