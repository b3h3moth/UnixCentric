#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef DataType *VectorDataType;

/* Lo scopo del programma e' di realizzare un vettore dinamico, il numero degli
elementi pertanto sara' definito dall'utente a run-time. */

int main(int argc, char *argv[]) {
	int size, i;
	VectorDataType vec;

	printf("Enter vector size: ");
	scanf("%d", &size);

    // Allocazione della memoria definita dall'utente
	vec = malloc(size * sizeof(DataType));

	// Inizializzazione del vettore
	printf("Inizializzazione vettore\n");
	for (i=0; i<size; i++) {
		printf("Init element (%.2d), give me an integer: ", i+1);
		scanf("%d", &vec[i]);
	}

    // Stampa ciascun elemento del vettore
	for (i=0; i<size; i++)
		printf("vec[%d]:\'%d\'\n", i, vec[i]);

	// Si libera la memoria
	free(vec);

	return(EXIT_SUCCESS);
}
