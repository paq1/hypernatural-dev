#ifndef __SPRITE_FACTORY_H__
#define __SPRITE_FACTORY_H__

#include <SDL2/SDL.h>
#include "../models/sprites/sprite.h"

typedef struct {
    sprite_t* sprite_test;
}sprite_factory_t;

sprite_factory_t * get_sprite_factory(SDL_Renderer *renderer);
void free_sprite_factory();

#endif // __SPRITE_FACTORY_H__