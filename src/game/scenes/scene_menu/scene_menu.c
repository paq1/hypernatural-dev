#include "scene_menu.h"

#define CURSOR_INIT_INDEX 0

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "../../enums/events_enum.h"
#include "../../factories/font_factory.h"
#include "../../factories/sprite_factory.h"
#include "../../services/draw_sprite_service.h"
#include "../../services/music_service.h"

/*private*/void update_cursor(scene_menu_t* scene_menu);

scene_menu_t* create_scene_menu(SDL_Renderer* renderer) {
    scene_menu_t* scene_menu = (scene_menu_t*) malloc(sizeof(scene_menu_t));
    SDL_Color color = { 255, 255, 255 };
    text_t* text_titre = create_text(renderer, "Hypernatural", 800 / 2 - 50, 0, get_font_factory()->main_font, color);
    text_t* text_aventure = create_text(renderer, "Aventure", 200, 375, get_font_factory()->main_font, color);
    text_t* text_donjon = create_text(renderer, "Donjons", 400, 375, get_font_factory()->main_font, color);
    text_t* text_options = create_text(renderer, "Options", 600, 375, get_font_factory()->main_font, color);
    cursor_t cursor = (cursor_t) { 0, 0};
    *scene_menu = (scene_menu_t) { "Menu", text_titre, text_aventure, text_donjon, text_options, 0.0, CURSOR_INIT_INDEX, cursor };
    update_cursor(scene_menu);
    return scene_menu;
}

void update_scene_menu(scene_menu_t* scene_menu, list_t* events, double dt) {

    play_music_menu();

    while (events) {
        enum event_enum event = *((enum event_enum*)(events->data));
        if (event == SPACE_BAR_PRESSED) {
            printf("INFO: evenement SPACE_BAR_PRESSED dans le menu\n");
        }
        if (event == RIGHT_PRESSED) {
            printf("INFO: evenement RIGHT_PRESSED dans le menu\n");
            if (scene_menu->cursor_index < 2) {
                scene_menu->cursor_index++;
            }
            else {
                scene_menu->cursor_index = 0;
            }

            update_cursor(scene_menu);

        }
        if (event == LEFT_PRESSED) {
            printf("INFO: evenement LEFT_PRESSED dans le menu\n");
            if (scene_menu->cursor_index > 0) {
                scene_menu->cursor_index--;
            }
            else {
                scene_menu->cursor_index = 2;
            }

            update_cursor(scene_menu);
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
    draw_text(scene_menu->text_aventure, renderer);
    draw_text(scene_menu->text_donjon, renderer);
    draw_text(scene_menu->text_options, renderer);
    draw_sprite_with_scale(get_sprite_factory(renderer)->sprite_test, renderer, scene_menu->x_test, 200, 4.0, 4.0);

    draw_sprite(get_sprite_factory(renderer)->sprite_test, renderer, scene_menu->cursor.x, scene_menu->cursor.y);
}

void free_scene_menu(scene_menu_t** scene_menu) {
    free_text(&(*scene_menu)->text_titre);
    free_text(&(*scene_menu)->text_aventure);
    free_text(&(*scene_menu)->text_donjon);
    free_text(&(*scene_menu)->text_options);
    free(*scene_menu);
    *scene_menu = NULL;
}

/*private*/void update_cursor(scene_menu_t* scene_menu) {
    if (scene_menu->cursor_index == 0) {
        scene_menu->cursor.x = 200;
        scene_menu->cursor.y = 400;
    } else if (scene_menu->cursor_index == 1) {
        scene_menu->cursor.x = 400;
        scene_menu->cursor.y = 400;
    } else if (scene_menu->cursor_index == 2) {
        scene_menu->cursor.x = 600;
        scene_menu->cursor.y = 400;
    }
}