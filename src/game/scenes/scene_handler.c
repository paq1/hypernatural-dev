#include "scene_handler.h"

#include <stdio.h>
#include <stdlib.h>

#include "../enums/events_enum.h"

/*private*/void gestion_evenement_menu(scene_handler_t* scene_handler, list_t* events);
/*private*/void gestion_evenement_donjon(scene_handler_t* scene_handler, list_t* events);
/*private*/void free_scene_menu(scene_menu_t** scene_menu);
/*private*/scene_donjon_t* create_scene_donjon();
/*private*/void free_scene_donjon(scene_donjon_t** scene_donjon);

scene_handler_t* create_scene_handler() {
    scene_menu_t* scene_menu = (scene_menu_t*) malloc(sizeof(scene_menu_t));
    *scene_menu = (scene_menu_t) { "Menu" };

    scene_handler_t* scene_handler = (scene_handler_t*) malloc(sizeof(scene_handler_t));
    *scene_handler = (scene_handler_t) { MENU, scene_menu, NULL };

    return scene_handler;
}

void handle_scenes(scene_handler_t* scene_handler, list_t* events, SDL_Renderer* renderer) {
    if (scene_handler->current_scene == MENU) {
        update_scene_menu(scene_handler->scene_menu, events);
        draw_scene_menu(scene_handler->scene_menu, renderer);
        gestion_evenement_menu(scene_handler, events);
    }
    else if (scene_handler->current_scene == DONJON) {
        update_scene_donjon(scene_handler->scene_donjon, events);
        draw_scene_donjon(scene_handler->scene_donjon, renderer);
        gestion_evenement_donjon(scene_handler, events);
    }
}

void free_scene_handler(scene_handler_t** scene_handler) {
    if (*scene_handler != NULL) {
        // todo : on supprime toute les scenes
        free_scene_menu(&(*scene_handler)->scene_menu);
        if ((*scene_handler)->scene_menu != NULL) {
            fprintf(stderr, "ERROR: la scene menu n'a pas ete liberee\n");
        }

        free_scene_donjon(&(*scene_handler)->scene_donjon);
        if ((*scene_handler)->scene_donjon != NULL) {
            fprintf(stderr, "ERROR: la scene donjon n'a pas ete liberee\n");
        }

        free(*scene_handler);
        *scene_handler = NULL;
    }
}

/*private*/void gestion_evenement_menu(scene_handler_t* scene_handler, list_t* events) {
    while (events) {
        enum event_enum event = *((enum event_enum*)(events->data));
        if (event == SPACE_BAR_PRESSED) {
            printf("INFO: lancement du mode donjon\n");
            scene_handler->current_scene = DONJON;
            if (scene_handler->scene_donjon == NULL) {
                scene_handler->scene_donjon = create_scene_donjon();
            }
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
            // todo : free_scene_donjon(&scene_handler->scene_donjon);
        }
        events = events->next;
    }
}

/*private*/void free_scene_menu(scene_menu_t** scene_menu) {
    if (*scene_menu != NULL) {
        free(*scene_menu);
        *scene_menu = NULL;
    }
}

/*private*/scene_donjon_t* create_scene_donjon() {
    scene_donjon_t* scene_donjon = (scene_donjon_t*) malloc(sizeof(scene_donjon_t));
    *scene_donjon = (scene_donjon_t) { "Donjon" };

    return scene_donjon;
}

/*private*/void free_scene_donjon(scene_donjon_t** scene_donjon) {
    if (*scene_donjon != NULL) {
        free(*scene_donjon);
        *scene_donjon = NULL;
    }
}
