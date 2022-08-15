#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "game/scenes/scene_handler.h"

int main(int arc, char * argv[]) {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
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

    scene_handler_t* scene_handler = create_scene_handler();

    while (launched) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {

            switch (event.type) {
                case SDL_QUIT:
                    launched = SDL_FALSE;
                    break;
                default:
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        handle_scenes(scene_handler);

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }


    free_scene_handler(&scene_handler);
    if (scene_handler != NULL) {
        fprintf(stderr, "ERROR: le scene handler n'a pas ete liberee\n");
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
