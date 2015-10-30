#include <stdio.h>
#include <stdlib.h>

// Array di lunghezza variabile (Variable Length Array)

int main(void) {
    int size;

    printf("How many number of elements to you want? ");
    scanf("%d", &size);

    int vec[size];  // Dal C99 in poi

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
