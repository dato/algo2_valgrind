#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define TAM 10

void rellenar_arreglo(int* arr, size_t n) {
	for (size_t i = 1; i <= n; i++) {
		arr[i] = i;
	}
}

void imprimir_arreglo(int* arr, size_t n) {
	for (size_t i = 1; i <= n; i++) {
		printf("%d\n", arr[i]);
	}
}

bool esta_ordenado(int* arr, size_t n) {
	for (size_t i = 0; i < n; i++) {
		if (arr[i] > arr[i+1]) {
			return false;
		}
	}
	return true;
}


int main(void) {
	int* arreglo = malloc(sizeof(int) * TAM);
	rellenar_arreglo(arr, TAM);
	imprimir_arreglo(arr, TAM);
	if (esta_ordenado(arr, TAM)) {
		printf("El arreglo esta ordenado\n");
	} else {
		printf("El arreglo no esta ordenado\n");
	}
	return 0;
}


