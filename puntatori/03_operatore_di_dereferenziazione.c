#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 10;
    int *ptr = &n;

    /* L'operatore di dereferenziazione ritorna il valore puntato dalla 
    variabile puntatore. */

    printf("dereferenziazione di ptr: %d\n", *ptr);

    /* Il valore di ritorno dell'operatore di dereferenziazione puo' essere
    assegnato ad un lvalue. */

    *ptr = 150; 

    /* In questo peraltro si va a modificare direttamente l'indirizzo di memoria
    puntato da ptr. */

    printf("valore di n: %d\n", n);

    return(EXIT_SUCCESS);
}
