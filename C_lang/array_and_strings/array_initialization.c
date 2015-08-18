#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(void) {

    // I primi 5 elelmenti sono inizializzati, il resto sara' posto a 0
    int vector_a[SIZE] = {10, 20, 30, 40, 50};

    // Un elemento in piu', warning (GCC)
    // warning: excess elements in array initializer
    int vector_b[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};

    // Tutti gli elementi inizializzati a 0.
    // Vale il discorso fatto per il primo vettore
    int vector_c[SIZE] = {0};

    // Lista di inizializzazione vuota, warning (GCC)
    // warning: ISO C forbids empty initializer braces
    int vector_d[SIZE] = { };

    return(EXIT_SUCCESS);
}
