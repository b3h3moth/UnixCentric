#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del programma e' la definizione ed implementazione di un array
multidimensionale dinamico. */

int main(void) {
    int rows = 2, cols = 5, i;

    // Alloca la memoria per l'array
    int **matrix = malloc(rows * sizeof(int *));

    // Alloca la memoria per ciascun elemento
    for (i=0; i<rows; i++)
        *(matrix + i) = malloc(cols * sizeof(int));

    return(EXIT_SUCCESS);
}
