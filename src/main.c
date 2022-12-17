#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

#include "game/scenes/scene_handler.h"

#include "core/sdd/list/list.h"
#include "game/enums/events_enum.h"

int main(int arc, char * argv[]) {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
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
                default:
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        
        SDL_RenderClear(renderer);

        // maj et affiche les scenes
        handle_scenes(scene_handler, events, renderer);

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

    free_scene_handler(&scene_handler);
    if (scene_handler != NULL) {
        fprintf(stderr, "ERROR: le scene handler n'a pas ete liberee\n");
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();

    return EXIT_SUCCESS;
}
