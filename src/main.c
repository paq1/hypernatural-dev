#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>

#include "game/scenes/scene_handler.h"

#include "core/sdd/list/list.h"
#include "game/enums/events_enum.h"
#include "game/factories/font_factory.h"
#include "game/factories/music_factory.h"
#include "game/factories/sprite_factory.h"
#include "game/services/text_service.h"

int main(int arc, char * argv[]) {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s", TTF_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    } else {
        printf("[info] SDL_ttf started\n");
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        TTF_Quit();
        SDL_Quit();
    }
        
    SDL_Window* window = SDL_CreateWindow(
        "Hypernatural",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED
    );
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    SDL_bool launched = SDL_TRUE;

    scene_handler_t* scene_handler = create_scene_handler(renderer);
    
    // todo : faire une factory pour les événements ;)
    enum event_enum* space_bar_pressed = (enum event_enum*) malloc(sizeof(enum event_enum));
    *space_bar_pressed = SPACE_BAR_PRESSED;
    enum event_enum* escape_pressed = (enum event_enum*) malloc(sizeof(enum event_enum));
    *escape_pressed = ESCAPE_PRESSED;
    enum event_enum* right_pressed = (enum event_enum*) malloc(sizeof(enum event_enum));
    *right_pressed = RIGHT_PRESSED;
    enum event_enum* left_pressed = (enum event_enum*) malloc(sizeof(enum event_enum));
    *left_pressed = LEFT_PRESSED;

    unsigned int old_ticks = SDL_GetTicks();
    double dt = 0.0;
    double timer = 0.0;
    int frames = 0;

    SDL_Color color = {255, 255, 255};  
    text_t* fps_text = create_text(
        renderer, 
        "fps :", 
        0, 
        0, 
        get_font_factory()->main_font, 
        color
    );

    while (launched) {
        SDL_Event event;
        list_t* events = NULL; // les evenement que l'on souhaite catcher pour les donner à nos scenes :)
        
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    launched = SDL_FALSE;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_SPACE) {
                        printf("space pressed (main)\n");
                        events = list_prepend(events, (void*) space_bar_pressed);
                    }
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        // printf("space pressed\n");
                        events = list_prepend(events, (void*) escape_pressed);
                    }
                    if (event.key.keysym.sym == SDLK_RIGHT) {
                        printf("right pressed\n");
                        events = list_prepend(events, (void*) right_pressed);
                    }
                    if (event.key.keysym.sym == SDLK_LEFT) {
                        printf("left pressed\n");
                        events = list_prepend(events, (void*) left_pressed);
                    }
                default:
                    break;
            }
        }

        unsigned int new_ticks = SDL_GetTicks();
        dt = (new_ticks - old_ticks) / 1000.0;
        old_ticks = new_ticks;

        timer += dt;
        frames++;
        if (timer > 1.0) {
            char buffer[50];
            sprintf(buffer, "fps : %d", frames);
            fps_text = get_updated_text_with_value(renderer, fps_text, buffer, get_font_factory()->main_font);
            timer = 0.0;
            frames = 0;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        
        SDL_RenderClear(renderer);

        // maj et affiche les scenes
        handle_scenes(scene_handler, events, renderer, dt);
        draw_text(fps_text, renderer);

        // suppression de la liste d'evenement dans le but de la clean
        free_list(&events);
        if (events) {
            fprintf(stderr, "ERROR: la liste d'evenements n'a pas ete liberee\n");
        }
        
        SDL_RenderPresent(renderer);
    }

    // suppression des evenements
    free(space_bar_pressed);
    free(escape_pressed);
    free(right_pressed);
    free(left_pressed);

    free_text(&fps_text);

    free_scene_handler(&scene_handler);
    if (scene_handler != NULL) {
        fprintf(stderr, "ERROR: le scene handler n'a pas ete liberee\n");
    }
    free_font_factory();
    free_sprite_factory();
    free_music_factory();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    SDL_Quit();
    TTF_Quit();

    return EXIT_SUCCESS;
}
