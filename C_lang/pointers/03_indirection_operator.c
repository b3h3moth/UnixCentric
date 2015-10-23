#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number = 10;
    int *ptr = &number;

    /* L'operatore di indirezione applicato a un puntatore produce il contenuto
    della locazione di memoria a cui il puntatore punta, che generalmente
    equivale ad accedere al valore della variabile puntata */

    printf("number: %d\n", number);
    printf("   ptr: %d\n", *ptr);

    /* Il valore di ritorno dell'operatore di indirezione puo' essere
    assegnato ad un lvalue. */

    int val = *ptr;
    printf("   val: %d\n", val);

    /* Un puntatore nel corso del programma puo' puntare verso altri indirizzi
    o valori, in questo caso cambiera' anche il valore della variabile a cui 
    puntava originariamente */

    *ptr = 150;
    printf("After\n");
    printf("   ptr: %d\n", *ptr);
    printf("number: %d\n", number);

    return(EXIT_SUCCESS);
}
