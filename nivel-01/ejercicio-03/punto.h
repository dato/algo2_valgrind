#ifndef __PUNTO_H__
#define __PUNTO_H__

typedef struct punto punto_t;

punto_t* punto_crear(double x, double y);

double punto_obtener_x(punto_t* punto);

double punto_obtener_y(punto_t* punto);

void punto_destruir(punto_t* punto);

#endif