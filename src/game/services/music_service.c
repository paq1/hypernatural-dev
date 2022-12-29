#include "music_service.h"

#include <stdlib.h>
#include <stdio.h>

void play_music_menu() {
    if (Mix_PlayingMusic() == 0) {
        Mix_Music* music_menu = get_music_factory()->music_menu;
        if (music_menu != NULL) {
            Mix_PlayMusic(music_menu, -1);
        } else {
            printf("ERROR: impossible de jouer la musique du menu\n");
        }
    }
}
void stop_music_menu() {
    Mix_HaltMusic();
}