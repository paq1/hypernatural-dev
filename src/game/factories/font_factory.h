#ifndef __FONT_FACTORY_H__
#define __FONT_FACTORY_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct {
    TTF_Font* main_font;
} font_factory_t;

font_factory_t* get_font_factory();
void free_font_factory();

#endif // __FONT_FACTORY_H__