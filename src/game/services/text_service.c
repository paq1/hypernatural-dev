#include "text_service.h"


text_t * create_text(SDL_Renderer *renderer, const char *value, int x, int y, TTF_Font *font, SDL_Color color) {
    SDL_Surface *surface_text = TTF_RenderText_Solid(font, value, color);
    if (surface_text == NULL) {
        return NULL;
    }

    SDL_Texture *texture_text = SDL_CreateTextureFromSurface(renderer, surface_text);
    if (texture_text == NULL) {
        SDL_FreeSurface(surface_text);
        return NULL;
    }
    SDL_FreeSurface(surface_text);

    text_t *text = (text_t *) SDL_malloc(sizeof(text_t));
    *text = (text_t){x, y, texture_text, color};
    return text;
}

void free_text(text_t** text) {
    SDL_DestroyTexture((*text)->texture);
    free(*text);
    *text = NULL;
}

text_t* get_updated_text_with_value(SDL_Renderer* renderer, text_t* text, char* value, TTF_Font* font) {
    SDL_Surface *surface_text = TTF_RenderText_Solid(font, value, text->color);
    if (surface_text == NULL) {
        return text; // todo retourner une erreur (mettre un optional)
    }
    SDL_Texture *texture_text = SDL_CreateTextureFromSurface(renderer, surface_text);
    if (texture_text == NULL) {
        SDL_FreeSurface(surface_text);
        return text; // todo retourner une erreur (mettre un optional)
    }
    SDL_FreeSurface(surface_text);

    SDL_DestroyTexture(text->texture);
    text->texture = texture_text;
    return text;
}

int draw_text(const text_t* text, SDL_Renderer *renderer) {
    SDL_Rect rect = {text->x, text->y, 0, 0};
    if (SDL_QueryTexture(text->texture, NULL, NULL, &rect.w, &rect.h) != 0) {
        return -1;
    }
    return SDL_RenderCopy(renderer, text->texture, NULL, &rect) != 0;
}
