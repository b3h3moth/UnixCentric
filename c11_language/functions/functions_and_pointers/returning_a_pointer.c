#include <stdio.h>
#include <stdlib.h>

int *create_array(int size);

/* Lo scopo del programma e' di scrivere una funzione che ritorni un puntatore.
La memoria sara' allocata mediante la funzione e sara' ritornato l'indirizzo
della memoria stessa. */

int main(void) {
    int *tmp;
    int *myarr = create_array(10);

    for (tmp = myarr; tmp < (myarr + 10); tmp++)
        printf("%d\n", *tmp);
    
    return(EXIT_SUCCESS);
}

/* La funzione crea un array di dimensione 'size', inizializzando ciascun 
elemento con il quadrato dell'indice. Infine ritorna la memoria allocata al
chiamante, ovvero l'indirizzo del primo elemento. */
int *create_array(int size) {
    int *array = malloc(sizeof(int) * size);

    for (int i=0; i<size; i++)
        *(array + i) = pow(i);

    return array;
}
