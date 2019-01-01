#include <stdio.h> 

// Suma los elementos de ambos arreglos hasta que alguno de los arreglos se acabe
int suma_mas_corto(int v1[], int n1, int v2[], int n2) {
	int min;
	if (n1 < n2) min = n1;
	else min = n2;
	
	int suma = 0;
	for (int i = 0; i < min; i++) {
		suma += v1[i] + v2[i];
	}
	return suma;
}


int main(void) {
	int arr1[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
	int arr2[] = {1, 5, 0, 13};
	printf("Resultado de sumar todos los elementos: %d\n", suma_mas_corto(arr1, 9, arr2, 4));
	printf("Resultado de sumar si tengo arreglos de mismo largo: %d\n", suma_mas_corto(arr1, 4, arr2, 4));
	printf("Resultado de sumar si alguno de los arreglos tiene largo 0: %d\n", suma_mas_corto(arr1, 0, arr2, 4));
}
