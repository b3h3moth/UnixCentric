#include <stdio.h>
#include <stdlib.h>

// Array length
#define SIZE 10

int main(void) {
    /* Quando si lavora con l'aritmetica dei puntatori si deve sempre tenere a
    mente la grandezza di ciascun tipo di dato:
    
    char    1 byte
    short   2 byte 
    int     4 byte
    long    8 byte
    float   4 byte
    double  8 byte

    Le operazioni permesse sono:
    - La somma di un intero a un puntatore;
    - La sottrazione da un puntatore di un intero;
    - La sottrazione da un puntatore di un puntatore.

    Inoltre vi e' anche il confronto tra puntatori mediante gli operatori
    relazionali, ma non e' un'operazione aritmetica in senso stretto.
    */

    // Sommare un intero a un puntatore
    int vec[SIZE] = {98, 16, 24, 10, 87, 28, 93, 11, 54, 92};
    int *ptr = vec;

    printf("            Array: ");
    for (int i=0; i<sizeof(vec)/sizeof(vec[0]); i++)
        printf("%d, ", vec[i]); 

    printf("\nAddress of vector: %d %p \n", *ptr, (void *)ptr);

    ptr++;                  /* 4 byte avanti */
    printf("ptr + %d (%2d byte): %d %p\n", 1, 4, *ptr, (void *)ptr);
    
    ptr += 1;               /* 4 byte avanti */
    printf("ptr + %d (%2d byte): %d %p\n", 1, 4, *ptr, (void *)ptr);

    printf("ptr + %d (%2d byte): %d %p\n", 4, 16, *(ptr+4), (void *)(ptr+4));

    return(EXIT_SUCCESS);
}
