#ifndef __MUSIC_FACTORY_H__
#define __MUSIC_FACTORY_H__

#include <SDL2/SDL_mixer.h>

typedef struct {
    Mix_Music* music_menu;
    Mix_Music* music_donjon;
} music_factory_t;

music_factory_t* get_music_factory();
void free_music_factory();

#endif // __MUSIC_FACTORY_H__