#include "scene_handler.h"

#include <stdio.h>
#include <stdlib.h>

/*private*/void free_scene_menu(scene_menu_t** scene_menu);

scene_handler_t* create_scene_handler() {
    scene_menu_t* scene_menu = (scene_menu_t*) malloc(sizeof(scene_menu_t));
    *scene_menu = (scene_menu_t) { "Menu" };

    scene_handler_t* scene_handler = (scene_handler_t*) malloc(sizeof(scene_handler_t));
    *scene_handler = (scene_handler_t) { MENU, scene_menu };

    return scene_handler;
}

void handle_scenes(scene_handler_t* scene_handler) {
    if (scene_handler->current_scene == MENU) {
        // on creer alors notre scene menu
        if (scene_handler->scene_menu == NULL) {
            printf("chargement du menu\n");
            scene_handler->scene_menu = (scene_menu_t*) malloc(sizeof(scene_menu_t));
            scene_handler->scene_menu->title = "Menu";
        }

        // on update notre scene menu
        update_scene_menu(scene_handler->scene_menu);

        // on affiche notre scene menu
        draw_scene_menu(scene_handler->scene_menu);
    }
}

void free_scene_handler(scene_handler_t** scene_handler) {
    if (*scene_handler != NULL) {
        // todo : on supprime toute les scenes
        free_scene_menu(&(*scene_handler)->scene_menu);
        if ((*scene_handler)->scene_menu != NULL) {
            fprintf(stderr, "ERROR: la scene menu n'a pas ete liberee\n");
        }

        free(*scene_handler);
        *scene_handler = NULL;
    }
}


/*private*/void free_scene_menu(scene_menu_t** scene_menu) {
    if (*scene_menu != NULL) {
        free(*scene_menu);
        *scene_menu = NULL;
    }
}
