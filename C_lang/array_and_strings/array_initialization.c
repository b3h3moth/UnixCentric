#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(void) {

    // Il vettore e' inizializzato col numero degli inizializzatori
    // In questo caso si tratta di un vettore di 5 elementi
    int vector_a[] = {10, 20, 30, 40, 50};

    // I primi 5 elelmenti sono inizializzati, il resto sara' posto a 0
    int vector_b[SIZE] = {10, 20, 30, 40, 50};

    // Un elemento in piu', warning (GCC)
    // warning: excess elements in array initializer
    int vector_c[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};

    // Tutti gli elementi inizializzati a 0.
    // Vale il discorso fatto per il primo vettore
    int vector_d[SIZE] = {0};

    // Lista di inizializzazione vuota, warning (GCC)
    // warning: ISO C forbids empty initializer braces
    int vector_e[SIZE] = { };

    // Dallo standard C99 vi sono i 'designated initializers', che permettono
    // di indicare esplicitamente gli elementi del vettore da inizializzare
    int vector_f[SIZE] = { 
        1, 
        [9] = 8, 
        [1] = 10, 
        4, 5, 
        [7] = 778, 
        8, 9, 7, 5};

    return(EXIT_SUCCESS);
}
