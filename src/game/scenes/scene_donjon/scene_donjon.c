#include "scene_donjon.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "../../enums/events_enum.h"
#include "../../services/draw_sprite_service.h"
#include "../../factories/sprite_factory.h"
#include "../../factories/font_factory.h"
#include "../../services/music_service.h"

#define VITESSE_CAMERA 200.0

/*private*/void update_direction_event(scene_donjon_t *scene_donjon, enum event_enum event);
/*private*/void update_camera(scene_donjon_t *scene_donjon, double dt, SDL_Renderer* renderer);
/*private*/void update_text_camera(scene_donjon_t *scene_donjon, double dt, SDL_Renderer* renderer);

scene_donjon_t* create_scene_donjon(SDL_Renderer* renderer) {
    scene_donjon_t* scene_donjon = malloc(sizeof(scene_donjon_t));
    camera_t camera = (camera_t) {-5.0, 70.0, VITESSE_CAMERA};
    SDL_Color white = {255, 255, 255};
    char buffer[50];
    sprintf(buffer, "camera (%lf, %lf)", camera.x, camera.y);
    text_t* pos_camera_text = create_text(renderer, buffer, 0, 32, get_font_factory()->main_font, white);
    *scene_donjon = (scene_donjon_t) {"Donjon", create_tilemap_empty(10, 10), camera, pos_camera_text, false, false, false, false};
    return scene_donjon;
}
void update_scene_donjon(scene_donjon_t* scene_donjon, list_t* events, double dt, SDL_Renderer* renderer) {
    play_music_donjon();
    while (events) {
        enum event_enum event = *((enum event_enum*)(events->data));
        if (event == SPACE_BAR_PRESSED) {
            printf("INFO: evenement SPACE_BAR_PRESSED dans le donjon\n");
        }
        update_direction_event(scene_donjon, event);
        events = events->next;
    }

    update_camera(scene_donjon, dt, renderer);
}
void draw_scene_donjon(scene_donjon_t* scene_donjon, SDL_Renderer* renderer) {
    draw_tilemap(scene_donjon->tilemap, renderer, scene_donjon->camera);
    draw_text(scene_donjon->pos_camera_text, renderer);
}

void free_scene_donjon(scene_donjon_t** scene_donjon) {
    free_tilemap(&(*scene_donjon)->tilemap);
    free_text(&(*scene_donjon)->pos_camera_text);
    free(*scene_donjon);
    *scene_donjon = NULL;
}

/*private*/void update_direction_event(scene_donjon_t *scene_donjon, enum event_enum event) {
    if (event == RIGHT_PRESSED) {
        scene_donjon->right_pressed = true;
    }
    if (event == RIGHT_UNPRESSED) {
        scene_donjon->right_pressed = false;
    }
    if (event == LEFT_PRESSED) {
        scene_donjon->left_pressed = true;
    }
    if (event == LEFT_UNPRESSED) {
        scene_donjon->left_pressed = false;
    }
    if (event == UP_PRESSED) {
        scene_donjon->up_pressed = true;
    }
    if (event == UP_UNPRESSED) {
        scene_donjon->up_pressed = false;
    }
    if (event == DOWN_PRESSED) {
        scene_donjon->down_pressed = true;
    }
    if (event == DOWN_UNPRESSED) {
        scene_donjon->down_pressed = false;
    }
}
/*private*/void update_camera(scene_donjon_t *scene_donjon, double dt, SDL_Renderer* renderer) {
    camera_t *camera = &scene_donjon->camera;

    double deplacement = (camera->vitesse * dt); 

    if (scene_donjon->right_pressed) {
        camera->x += deplacement;
    }
    if (scene_donjon->left_pressed) {
        camera->x -= deplacement;
    }
    if (scene_donjon->up_pressed) {
        camera->y -= deplacement;
    }
    if (scene_donjon->down_pressed) {
        camera->y += deplacement;
    }

    // on met a jour le texte de la position de la camera
    update_text_camera(scene_donjon, dt, renderer);
}

/*private*/void update_text_camera(scene_donjon_t *scene_donjon, double dt, SDL_Renderer* renderer) {
    char buffer[50];
    camera_t *camera = &scene_donjon->camera;
    sprintf(buffer, "camera (%lf,%lf)", camera->x, camera->y);
    scene_donjon->pos_camera_text = get_updated_text_with_value(
        renderer, 
        scene_donjon->pos_camera_text,
        buffer, 
        get_font_factory()->main_font
    );
}
