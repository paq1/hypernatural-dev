#ifndef __COLLIDE_SERVICE_H__
#define __COLLIDE_SERVICE_H__

#include <stdbool.h>$
#include "../../core/sdd/vecteur/vecteur2d.h"

bool collide_box_with_point(
    vecteur2d_t point, 
    vecteur2d_t box_position, 
    vecteur2d_t box_size
);
bool collide_box_with_other_box(
    vecteur2d_t box_position, 
    vecteur2d_t box_size, 
    vecteur2d_t other_box_position, 
    vecteur2d_t other_box_size
);

#endif // __COLLIDE_SERVICE_H__