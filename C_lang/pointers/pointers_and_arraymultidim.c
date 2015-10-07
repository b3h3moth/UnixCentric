#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int data[][3] = {
        {10, 20, 30},
        {40, 50, 60},
    };

    // Entrambi ritornano l'indirizzo dell'elemento 0
    printf("        data: %p\n", (void *)data);
    printf("    &data[0]: %p\n", (void *)&data[0]);

    // Ritorna l'indirizzo dell'elemento 0
    printf("     data[0]: %p\n", (void *)data[0]);

    // Ritorna l'indirizzo dell'elemento [0][0]
    printf(" &data[0][0]: %p\n", (void *)&data[0][0]);

    // Ritorna l'indirizzo iniziale dell'array
    printf("       &data: %p\n", (void *)&data);

    // Entrambi puntano all'indirizzo 0
    printf("       *data: %p\n", (void *)*data);
    printf("   *&data[0]: %p\n", (void *)*&data[0]);

    // Ritorna il valore del primo elemento, [0][0]
    printf("    *data[0]: %d\n", *data[0]);

    // Ritorna il valore del primo elemento, [0][0]
    printf("*&data[0][0]: %d\n", *&data[0][0]);
    return(EXIT_SUCCESS);
}
