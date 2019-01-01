#include <stdio.h>
#include "punto.h"

int main() {
    punto_t* p = punto_crear(3.2, 4.1);
    
    printf("La coordenada x del punto es: %lf\n", punto_obtener_x(p));
    printf("La coordenada y del punto es: %lf\n", punto_obtener_y(p));
    
    punto_destruir(p);
}