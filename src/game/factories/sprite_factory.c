#include "sprite_factory.h"
#include <stdlib.h>
#include <stdio.h>

/*private*/sprite_factory_t* create_sprite_factory();
/*private*/sprite_factory_t* sprite_factory = NULL;

sprite_factory_t* get_sprite_factory(SDL_Renderer *renderer) {
  if (sprite_factory == NULL) {
    sprite_factory = create_sprite_factory(renderer);
  }
  return sprite_factory;
}

void free_sprite_factory() {
  if (sprite_factory != NULL) {
    free_sprite(&sprite_factory->sprite_test);
    free_sprite(&sprite_factory->sprite_tile_grass);
    free_sprite(&sprite_factory->sprite_tile_wall);
    free(sprite_factory);
    sprite_factory = NULL;
  }
}

/*private*/sprite_factory_t * create_sprite_factory(SDL_Renderer *renderer) {
  sprite_factory_t* sprite_factory = malloc(sizeof(sprite_factory_t));
  sprite_factory->sprite_test = create_sprite_bmp("../assets/sprites/test/test.bmp", renderer);
  sprite_factory->sprite_tile_grass = create_sprite_bmp("../assets/sprites/tiles/grass.bmp", renderer);
  sprite_factory->sprite_tile_wall = create_sprite_bmp("../assets/sprites/tiles/wall.bmp", renderer);
  if (sprite_factory->sprite_test == NULL) {
    printf("ERROR: sprite test non charge\n");
    exit(EXIT_FAILURE);
  }
  return sprite_factory;
}