#ifndef __DRAW_SPRITE_SERVICE_H__
#define __DRAW_SPRITE_SERVICE_H__

#include "../models/sprites/sprite.h"

int draw_sprite(const sprite_t *sprite, SDL_Renderer *renderer, double x, double y);
int draw_sprite_with_scale(const sprite_t *sprite, SDL_Renderer *renderer, double x, double y, double scaleX, double scaleY);

#endif