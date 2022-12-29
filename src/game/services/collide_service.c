#include "collide_service.h"

bool collide_box_with_point(
    vecteur2d_t point, 
    vecteur2d_t box_position, 
    vecteur2d_t box_size
) {
    return 
        point.x >= box_position.x &&
        point.x <= box_position.x + box_size.x &&
        point.y >= box_position.y &&
        point.y <= box_position.y + box_size.y
    ;
}
bool collide_box_with_other_box(
    vecteur2d_t box_position, 
    vecteur2d_t box_size, 
    vecteur2d_t other_box_position, 
    vecteur2d_t other_box_size
) {
    // todo: a tester
    return 
        collide_box_with_point(box_position, other_box_position, other_box_size) ||
        collide_box_with_point(
            (vecteur2d_t) {box_position.x + box_size.x, box_position.y}, 
            other_box_position, 
            other_box_size
        ) ||
        collide_box_with_point(
            (vecteur2d_t) {box_position.x, box_position.y + box_size.y}, 
            other_box_position, 
            other_box_size
        ) ||
        collide_box_with_point(
            (vecteur2d_t) {box_position.x + box_size.x, box_position.y + box_size.y}, 
            other_box_position, 
            other_box_size
        )
    ;
}