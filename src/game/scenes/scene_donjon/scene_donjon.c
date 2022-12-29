#include "scene_donjon.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "../../enums/events_enum.h"
#include "../../services/draw_sprite_service.h"
#include "../../factories/sprite_factory.h"

scene_donjon_t* create_scene_donjon(SDL_Renderer* renderer) {
    scene_donjon_t* scene_donjon = malloc(sizeof(scene_donjon_t));

    int ** tiles = (int**)malloc(sizeof(int*) * 10);
    for (int i = 0; i < 10; i++) {
        tiles[i] = (int*)malloc(sizeof(int) * 10);
        for (int j = 0; j < 10; j++) {
            tiles[i][j] = 0;
        }
    }

    tiles[4][4] = 1;

    *scene_donjon = (scene_donjon_t) {"Donjon", (tilemap_t) {tiles}};
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
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (scene_donjon->tilemap.tilemap[i][j] == 0) {
                draw_sprite_with_scale(get_sprite_factory(renderer)->sprite_tile_grass, renderer, i * 32, j * 32, 0.125, 0.125);
            } else if (scene_donjon->tilemap.tilemap[i][j] == 1) {
                draw_sprite_with_scale(get_sprite_factory(renderer)->sprite_tile_wall, renderer, i * 32, j * 32, 0.125, 0.125);
            }
        }
    }
}

void free_scene_donjon(scene_donjon_t** scene_donjon) {
    free(*scene_donjon);
    *scene_donjon = NULL;
}