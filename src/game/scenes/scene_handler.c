#include "scene_handler.h"

#include <stdio.h>
#include <stdlib.h>

#include "../enums/events_enum.h"
#include "../services/music_service.h"

/*private*/void gestion_evenement_menu(scene_handler_t* scene_handler, list_t* events, SDL_Renderer* renderer);
/*private*/void gestion_evenement_donjon(scene_handler_t* scene_handler, list_t* events);
/*private*/scene_donjon_t* create_scene_donjon();
/*private*/void free_scene_donjon(scene_donjon_t** scene_donjon);

scene_handler_t* create_scene_handler(SDL_Renderer* renderer) {
    printf("[info] creation scene menu\n");
    scene_menu_t* scene_menu = create_scene_menu(renderer);

    scene_handler_t* scene_handler = (scene_handler_t*) malloc(sizeof(scene_handler_t));
    *scene_handler = (scene_handler_t) { MENU, scene_menu, NULL, NULL };

    return scene_handler;
}

void handle_scenes(scene_handler_t* scene_handler, list_t* events, SDL_Renderer* renderer, double dt) {
    if (scene_handler->current_scene == MENU) {
        update_scene_menu(scene_handler->scene_menu, events, dt);
        draw_scene_menu(scene_handler->scene_menu, renderer);
        gestion_evenement_menu(scene_handler, events, renderer);
    }
    else if (scene_handler->current_scene == DONJON) {
        update_scene_donjon(scene_handler->scene_donjon, events, dt, renderer);
        draw_scene_donjon(scene_handler->scene_donjon, renderer);
        gestion_evenement_donjon(scene_handler, events);
    } else if (scene_handler->current_scene == CABANE) {
        // todo : ajouter la gestion de la scene cabane
        update_scene_cabane(scene_handler->scene_cabane, events, dt);
        draw_scene_cabane(scene_handler->scene_cabane, renderer);
        // gestion_evenement_cabane(scene_handler, events);
    }
}

void free_scene_handler(scene_handler_t** scene_handler) {
    if (*scene_handler != NULL) {
        // todo : on supprime toute les scenes
        if ((*scene_handler)->scene_menu != NULL) {
            free_scene_menu(&(*scene_handler)->scene_menu);
        }
        if ((*scene_handler)->scene_menu != NULL) {
            fprintf(stderr, "ERROR: la scene menu n'a pas ete liberee\n");
        }
        
        if ((*scene_handler)->scene_donjon != NULL) {
            free_scene_donjon(&(*scene_handler)->scene_donjon);
        }
        if ((*scene_handler)->scene_donjon != NULL) {
            fprintf(stderr, "ERROR: la scene donjon n'a pas ete liberee\n");
        }

        if ((*scene_handler)->scene_cabane != NULL) {
            free_scene_cabane(&(*scene_handler)->scene_cabane);
        }
        if ((*scene_handler)->scene_cabane != NULL) {
            fprintf(stderr, "ERROR: la scene cabane n'a pas ete liberee\n");
        }

        free(*scene_handler);
        *scene_handler = NULL;
    }
}

/*private*/void gestion_evenement_menu(scene_handler_t* scene_handler, list_t* events, SDL_Renderer* renderer) {
    while (events) {
        enum event_enum event = *((enum event_enum*)(events->data));
        if (event == SPACE_BAR_PRESSED && scene_handler->scene_menu->cursor_index == 1) {
            printf("INFO: lancement du mode donjon\n");
            scene_handler->current_scene = DONJON;
            if (scene_handler->scene_donjon == NULL) {
                scene_handler->scene_donjon = create_scene_donjon(renderer);
            }
            stop_music_menu();
        } else if (event == SPACE_BAR_PRESSED && scene_handler->scene_menu->cursor_index == 0) {
            printf("INFO: goto scene cabane\n");
            scene_handler->current_scene = CABANE;
            if (scene_handler->scene_cabane == NULL) {
                scene_handler->scene_cabane = create_scene_cabane(renderer);
            }
            stop_music_menu();
        }
        events = events->next;
    }
}

/*private*/void gestion_evenement_donjon(scene_handler_t* scene_handler, list_t* events) {
    while (events) {
        enum event_enum event = *((enum event_enum*)(events->data));
        if (event == ESCAPE_PRESSED) {
            printf("INFO: retour au menu\n");
            scene_handler->current_scene = MENU;
            free_scene_donjon(&scene_handler->scene_donjon);
            stop_music();
        }
        events = events->next;
    }
}
