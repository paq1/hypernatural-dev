#ifndef __TEXT_SERVICE_H__
#define __TEXT_SERVICE_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct {
    int x, y;
    SDL_Texture *texture;
    SDL_Color color;
} text_t;

text_t* create_text(SDL_Renderer* renderer, const char* value, int x, int y, TTF_Font* font, SDL_Color color);
void free_text(text_t** text);

text_t* get_updated_text_with_value(SDL_Renderer* renderer, text_t* text, char* value, TTF_Font* font);

int draw_text(const text_t* text, SDL_Renderer *renderer);

#endif // __TEXT_SERVICE_H__