#include "tilemap.h"

#include <stdlib.h>

#include "../../../factories/sprite_factory.h"
#include "../../../services/draw_sprite_service.h"

tilemap_t* create_tilemap_empty(int rows, int cols) {
    tilemap_t* tilemap = (tilemap_t*) malloc(sizeof(tilemap_t));

    int ** tiles = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        tiles[i] = (int*)malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            tiles[i][j] = 0;
        }
    }

    *tilemap = (tilemap_t) {rows, cols, tiles};

    return tilemap;
}

void free_tilemap(tilemap_t** tilemap) {
    for (int i = 0; i < (*tilemap)->rows; i++) {
        free((*tilemap)->tilemap[i]);
    }
    free((*tilemap)->tilemap);
    free(*tilemap);
    *tilemap = NULL;
}

void draw_tilemap(tilemap_t* tilemap, SDL_Renderer* renderer) {
    for (int i = 0; i < tilemap->rows; i++) {
        for (int j = 0; j < tilemap->cols; j++) {
            if (tilemap->tilemap[i][j] == 0) {
                draw_sprite_with_scale(
                    get_sprite_factory(renderer)->sprite_tile_grass, 
                    renderer, 
                    i * 32, 
                    j * 32, 
                    0.125, 
                    0.125
                );
            } else if (tilemap->tilemap[i][j] == 1) {
                draw_sprite_with_scale(
                    get_sprite_factory(renderer)->sprite_tile_wall, 
                    renderer, 
                    i * 32, 
                    j * 32, 
                    0.125,
                    0.125
                );
            }
        }
    }
}