#ifndef __TILEMAP_H__
#define __TILEMAP_H__

#include <SDL2/SDL.h>

#include "../../../models/camera/camera.h"

typedef struct {
    int rows, cols;
    int** tilemap;
} tilemap_t;


tilemap_t* create_tilemap_empty(int rows, int cols);
void free_tilemap(tilemap_t** tilemap);

void draw_tilemap(tilemap_t* tilemap, SDL_Renderer* renderer, camera_t camera);

#endif // __TILEMAP_H__