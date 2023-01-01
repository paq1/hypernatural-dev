#include "music_factory.h"

#include <stdlib.h>
#include <stdio.h>

/*private*/music_factory_t* create_music_factory();
/*private*/music_factory_t* music_factory = NULL;

music_factory_t* get_music_factory() {
    if (music_factory == NULL) {
        music_factory = create_music_factory();
    }
    return music_factory;
}
void free_music_factory() {
    if (music_factory != NULL) {
        Mix_FreeMusic(music_factory->music_menu);
        Mix_FreeMusic(music_factory->music_donjon);
        free(music_factory);
        music_factory = NULL;
    }
}

/*private*/music_factory_t* create_music_factory() {
    printf("[info]: creation de la music factory\n");
    music_factory_t* music_factory = malloc(sizeof(music_factory_t));
    music_factory->music_menu = Mix_LoadMUS("../assets/musics/digital-love.wav");
    if (music_factory->music_menu == NULL) {
        printf("ERROR: impossible de charger la musique du menu\n");
        exit(EXIT_FAILURE);
    }

    music_factory->music_donjon = Mix_LoadMUS("../assets/musics/MrKey_Friedrich_LMK.mp3");
    if (music_factory->music_donjon == NULL) {
        printf("ERROR: impossible de charger la musique du donjon\n");
        exit(EXIT_FAILURE);
    }
    return music_factory;
}