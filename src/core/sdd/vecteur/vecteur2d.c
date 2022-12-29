#include "vecteur2d.h"

vecteur2d_t create_v2d(double x, double y, option_t option_z) {
    return (vecteur2d_t) {x, y, option_z};
}