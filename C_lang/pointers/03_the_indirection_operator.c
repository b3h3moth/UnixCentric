#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 10;
    int *ptr = &n;

    /* L'operatore di indirezione applicato a un puntatore produce il contenuto
    della locazione di memoria a cui il puntatore punta, che generalmente
    equivale ad accedere al valore della variabile puntata */

    printf("*ptr: %d\n", *ptr);

    /* Il valore di ritorno dell'operatore di indirezione puo' essere
    assegnato ad un lvalue. */

    int val = *ptr;
    printf("val: %d\n", val);

    /* Un puntatore nel corso del programma puo' puntare verso altri indirizzi
    o valori */
    *ptr = 150;
    printf("*ptr: %d\n", *ptr);

    return(EXIT_SUCCESS);
}
