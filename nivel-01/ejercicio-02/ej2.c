#include <stdio.h>
#include <stddef.h>
#define TAM 10

int main(void) {
	int arr[TAM];
	for (size_t i = 0; i <= TAM; i++) {
		arr[i] = (int) i;
	}
	for (size_t i = 0; i <= TAM; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
