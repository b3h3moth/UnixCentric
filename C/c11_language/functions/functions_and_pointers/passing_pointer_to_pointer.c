#include <stdio.h>
#include <stdlib.h>

void create_array(int **array, int size);

/* Lo scopo del programma e' di scrivere una funzione che accetti come
parametro un puntatore a puntatore e dal quale creare un array la cui 
dimensione sara' definita mediante un ulteriore parametro ricevuto in
input. */

int main(int argc, char *argv[]) {
    int *myarr = NULL;
    int *tmp = NULL;
    int sz;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <array size>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sz = atoi(argv[1]);
    create_array(&myarr, sz);

    for (tmp = myarr; tmp < (myarr + sz); tmp++)
        printf("%d\n", *tmp);

    // E' responsabilita' del chiamante rilasciare la memoria
    free(myarr);

    return(EXIT_SUCCESS);
}

/* La funzione alloca la memoria necessaria per l'array di dimensione 'size', 
inizializzando ciascun elemento con la potenza dell'indice. */
void create_array(int **array, int size) {
    *array = malloc(sizeof(int) * size);

    if (*array == NULL) {
        fprintf(stderr, "Err. can't allocate memory");
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<size; i++)
        (*array)[i] = i * i; // Equivalente a: *(*array + i) = i*i;
}
