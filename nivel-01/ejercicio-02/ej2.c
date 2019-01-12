#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#define TAM 10

void rellenar_arreglo(int* arr, size_t n) {
	for (size_t i = 0; i < n; i++) {
		arr[i] = i;
	}
}

void imprimir_arreglo(int* arr, size_t n) {
	for (size_t i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
}

bool esta_ordenado(int* arr, size_t n) {
	for (size_t i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i+1]) {
			return false;
		}
	}
	return true;
}


int main(void) {
	int* arreglo = malloc(sizeof(int) * TAM);
	rellenar_arreglo(arreglo, TAM);
	imprimir_arreglo(arreglo, TAM);
	if (esta_ordenado(arreglo, TAM)) {
		printf("El arreglo esta ordenado\n");
	} else {
		printf("El arreglo no esta ordenado\n");
	}
	free(arreglo);
	return 0;
}


