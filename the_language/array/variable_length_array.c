#include <stdio.h>
#include <stdlib.h>

/* I vettori a lunghezza variabile (Variable-length arrays) sono stati 
introdotti nello standard c99, essi consentono di specificare la lunghezza di
un vettore mediante una espressione non costante */

int main(void) {
    int size;

    printf("Give di size of the array: ");
    scanf("%d", &size);

    /* La lunghezza del vettore e' impostata da un'espressione non costante,
    che nel caso specifico e' 'size' */
    int vec[size];  

    printf("Initialize an array of %d elements:\n", size);
    for(int i=0; i<size; i++) {
        printf("\tvector[%d]: ", i);
        scanf("%d", &vec[i]);
    }

    printf("Print each element:\n");
    for(int j=0; j<size; j++)
        printf("\tvec[%d] = %d\n", j, vec[j]);

    return(EXIT_SUCCESS);
}
