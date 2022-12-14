#include "font_factory.h"
#include <stdlib.h>
#include <stdio.h>

/*private*/font_factory_t* create_font_factory();
/*private*/font_factory_t* font_factory = NULL;

font_factory_t* get_font_factory() {
    if (font_factory == NULL) {
        font_factory = create_font_factory();
        if (font_factory->main_font == NULL) {
            printf("ERROR: TTF_OpenFont: %s\n", TTF_GetError());
            exit(EXIT_FAILURE);
        }
    }
    return font_factory;
}

void free_font_factory() {
    if (font_factory != NULL) {
        TTF_CloseFont(font_factory->main_font);
        free(font_factory);
        font_factory = NULL;
    }
}

/*private*/font_factory_t* create_font_factory() {
    printf("[info]: creation de la font factory\n");
    font_factory_t* font_factory = malloc(sizeof(font_factory_t));
    font_factory->main_font = TTF_OpenFont("../assets/fonts/dpcomic.ttf", 25);
    return font_factory;
}
