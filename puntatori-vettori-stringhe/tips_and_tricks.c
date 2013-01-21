#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN 10

int main(void) {
    int array_int[ARR_LEN];
    int *ptr;
    int i;

    /* Ciascun elemento dell'array, essendo un intero, ha una dimensione di 
    4 byte, per cui essendo l'array di dimensione ARR_LEN, il totale della
    dimensione e' di 40 byte. */
    for (i=0; i<ARR_LEN; i++)
        array_int[i] = 100+i;

    printf("array_int = 0x%lx\n", (unsigned long)array_int);

    /* L'array creato altro non e' che un puntatore al suo primo elemento, per
    cui puo' essere assegnato ad un altro puntatore */
    ptr = array_int;

    for (i=0; i<ARR_LEN; i++) {
        printf("i=%d - array_int[%d]=%d - ptr=0x%lx - ptr=%d -"
                "(ptr-array_int)=%d\n", i, i,array_int[i], (unsigned long) ptr, 
                *ptr, (int)(ptr-array_int));
        ptr++;          /* Da notare ptr-array_int, in questo caso entra in */
    }                   /* Gioco l'aritmetica dei puntatori, nello specifico si
                           sta chiedendo il numero di elementi tra ptr e 
                           array_int, che sarebbe in effetti la differenza dei
                           due puntatori diviso il dimensione di un elemento,
                           che nel caso specifico e' 4Byte. */

    return(EXIT_SUCCESS);
}
