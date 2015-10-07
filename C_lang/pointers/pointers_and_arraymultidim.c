#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int data[][3] = {
        {10, 20, 30},
        {40, 50, 60},
    };

    int *p = *&data;

    // Puntano entrambi al primo elemento dell'array di 3 elementi
    printf("       data: %p\n", (void *)data);
    printf("   &data[0]: %p\n", (void *)&data[0]);

    // Puntano entrambi all'indirizzo dell'elemento 0 dell'array
    printf("    data[0]: %p\n", (void *)data[0]);
    printf("&data[0][0]: %p\n", (void *)&data[0][0]);

    // Punta all'array, l'indirizzo iniziale
    printf("      &data: %p\n", (void *)&data);

    return(EXIT_SUCCESS);
}
