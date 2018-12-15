#include <stdio.h> 
#include <stdlib.h>

int main(void) {
	int* a = malloc(sizeof(int));
	*a = 10;
	printf("Hola mundo: %d\n", *a);
	printf("Hola mundo: %p\n", a);
	return 0;
}
