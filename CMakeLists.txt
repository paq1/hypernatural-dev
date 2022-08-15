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
        src/game/scenes/scene_menu/scene_menu.c
        src/game/scenes/scene_donjon/scene_donjon.c
        src/game/scenes/scene_handler.c
)

# linkage librairie
if (WIN32)
        target_link_libraries(
                ${NOM_PROJET}
                -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
        )
endif(WIN32)

if (UNIX)
        target_link_libraries(
                ${NOM_PROJET}
                -lSDL2 -lSDL2_mixer
        )
endif(UNIX)
