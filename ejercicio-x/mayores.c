// mayores.c - Lee un CSV de personas y muestra por pantalla las mayores de edad.
//
// Ver archivo README.md para una lista detallada de requerimientos.

#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

struct persona {
    char *nombre;
    char *apellido;
    unsigned edad;
    char *linea_csv;
};

//
// Extrae de p->linea_csv el nombre y el apellido (primer campo).
//
static bool persona_nombre(struct persona *p) {
    // Encontrar la primera coma en la línea.
    char *coma = strchr(p->linea_csv, ',');

    if (!coma) {
        return false;
    }

    // Hacer una copia de esa parte de la cadena
    // (sin incluir la coma).
    char *nom_completo = strndup(p->linea_csv, coma - p->linea_csv);

    // Separar nombre y apellido. Puede que no haya apellido.
    char *espacio = strchr(nom_completo, ' ');
    if (espacio) {
        *espacio = '\0';
        p->nombre = nom_completo;  // Ya no incluye apellido.
        p->apellido = espacio + 1; // Hasta el final de la copia.
    }
    else {
        p->nombre = nom_completo;
        p->apellido = strdup("");
    }

    return true;
}

//
// Extrae de p->linea_csv la fecha de nacimiento (segundo campo) y calcula la edad.
//
static bool persona_edad(struct persona *p) {
    char *substr = strchr(p->linea_csv, ',');

    if (!substr) {
        return false;
    }
    else {
        substr++; // Posicionarnos en el primer dígito del año.
    }

    /*
     * TODO: cálculo verdadero de la edad;
     * int d, m, y;
     * sscanf(substr, "%d-%d-%d", &y, &m, &d);
     */

    // XXX Hack para conseguir los errores de Valgrind.
    if (!(*substr >= '0' && *substr <= '9')) {
        return false;
    }
    if (*substr == '2') {
        p->edad = 17;
    } else {
        p->edad = 30;
    }

    return true;
}

//
// Libera la memoria de un struct persona.
//
static void free_persona(void *ptr) {
    struct persona *p = ptr;
    free(p->nombre);
    if (p->apellido && strlen(p->apellido) == 0) {
        // No había apellido e hicimos strdup("").
        free(p->apellido);
    }
    free(p->linea_csv);
    free(p);
}


//
// Lee una línea en formato CSV y guarda la información de la persona.
//
static bool leer_persona(char *linea, struct persona *per) {
    per->linea_csv = linea;

    if (persona_edad(per) && persona_nombre(per)) {
        if (per->edad >= 18) {
            per->linea_csv = NULL;
            return true;
        }
        else {
            per->linea_csv = NULL;
            return false; // Menor de edad.
        }
    }

    free_persona(per);
    per = NULL;
    return false;
}

int main(int argc, char *argv[]) {
    FILE *csv;

    if (argc <= 1) {
        fprintf(stderr, "Uso: %s <archivo.csv>\n", argv[0]);
        return 1;
    }

    if ((csv = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo: %s\n", argv[1]);
        return 1;
    }

    char *linea = NULL;
    size_t size = 0;
    lista_t *personas = lista_crear();

    while (getline(&linea, &size, csv) >= 0) {
        struct persona *per = malloc(sizeof(struct persona));
        if (per == NULL) {
            fprintf(stderr, "Oh no! Falló malloc!\n");
            return 2;
        }
        if (leer_persona(linea, per)) {
            lista_insertar_ultimo(personas, per);
        }
        else {
            // leer_persona devolvió false: línea en formato incorrecto.
            // Se libera memoria si no lo hizo leer_persona() ya.
            if (per != NULL) {
                free(per);
            }
        }
    }
    lista_iter_t *iter = lista_iter_crear(personas);

    while (iter && !lista_iter_al_final(iter)) {
        struct persona *per = lista_iter_ver_actual(iter);
        if (per->edad >= 18) {
            if (strlen(per->apellido) == 0) {
                printf("%s (%d)\n", per->nombre, per->edad);
            } else {
                printf("%s, %s (%d)\n", per->apellido, per->nombre, per->edad);
            }
        }
        lista_iter_avanzar(iter);
    }

    fclose(csv);
    lista_iter_destruir(iter);
    lista_destruir(personas, free_persona);
}

