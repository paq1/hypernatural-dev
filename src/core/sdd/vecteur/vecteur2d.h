#ifndef __VECTEUR2D_H__
#define __VECTEUR2D_H__

#include "../option/option.h"

typedef struct {
    double x, y;
    option_t option_z;
} vecteur2d_t;

vecteur2d_t create_v2d(double x, double y, option_t option_z);

#endif // __VECTEUR2D_H__