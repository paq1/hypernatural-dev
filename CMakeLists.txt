cmake_minimum_required(VERSION 3.17)

set(NOM_PROJET hypernatural)
set(BIN bin)
project(${NOM_PROJET})

set(CMAKE_C_STANDARD 11)

# lib sdl2 and others
if (WIN32)
        include_directories(include)
        link_directories(lib)
endif(WIN32)


add_executable(
        ${NOM_PROJET} 
        src/main.c
        src/core/sdd/list/list.c
        src/core/sdd/option/option.c
        src/core/sdd/vecteur/vecteur2d.c
        src/game/factories/font_factory.c
        src/game/factories/music_factory.c
        src/game/factories/sprite_factory.c
        src/game/models/sprites/sprite.c
        src/game/services/text_service.c
        src/game/services/draw_sprite_service.c
        src/game/services/music_service.c
        src/game/scenes/scene_menu/scene_menu.c
        src/game/scenes/scene_donjon/scene_donjon.c
        src/game/scenes/scene_donjon/tilemap/tilemap.c
        src/game/scenes/scene_cabane/scene_cabane.c
        src/game/scenes/scene_handler.c
)

# linkage librairie
if (WIN32)
        target_link_libraries(
                ${NOM_PROJET}
                -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer
        )
endif(WIN32)

if (UNIX)
        target_link_libraries(
                ${NOM_PROJET}
                -lSDL2 -lSDL2_mixer -lSDL2_ttf
        )
endif(UNIX)
