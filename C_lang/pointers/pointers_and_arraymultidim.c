#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int data[][3] = {   // Equivalente a data[2][3]
        {10, 20, 30},
        {40, 50, 60},
    };

    /* Stampano l'indirizzo iniziale dell'array multidimensionale o del primo
    elemento  */
    printf("          data: %p\n", (void *)data);
    printf("      &data[0]: %p\n", (void *)&data[0]);
    printf("       data[0]: %p\n", (void *)data[0]);
    printf("         &data: %p\n", (void *)&data);
    printf("         *data: %p\n", (void *)*data);
    printf("     *&data[0]: %p\n", (void *)*&data[0]);
    printf("        *&data: %p\n", (void *)*&data);
    printf("   &data[0][0]: %p\n", (void *)&data[0][0]);

    // Stampano il valore del primo elemento del primo sottoarray, [0][0]
    printf("      *data[0]: %d\n", *data[0]);
    printf("  *&data[0][0]: %d\n", *&data[0][0]);

    // Stampa l'indirizzo del primo elemento del secondo sottoarray
    printf("     *(data+1): %p\n", (void *)*(data +1));
    
    // Stampa il valore del primo elemento del secondo sottoarray [1][0]
    printf("  *(*(data+1)): %d\n", *(*(data + 1)));

    // Stampa l'indirizzo del secondo elemento del secondo sottoarray [1][1]
    printf("   *(data+1)+1: %p\n", (void *)(*(data + 1) + 1));

    // Stampa il valore del secondo elemento del secondo sottoarray [1][1]
    printf("*(*(data+1)+1): %d\n", *(*(data + 1) + 1) );
    
    return(EXIT_SUCCESS);
}
