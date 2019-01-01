#include "punto.h"
#include <stdlib.h>

struct punto {
    double x;
    double y;
};


punto_t* punto_crear(double x, double y) {
	punto_t punto;
    punto.x = x;
    punto.y = y;    
    return &punto;    
}

double punto_obtener_x(punto_t* punto) {
    return punto->x;
}

double punto_obtener_y(punto_t* punto) {
    return punto->y;
}

void punto_destruir(punto_t* punto) {
    free(punto);
}
