#include <stdio.h>
#include <stdlib.h>

enum { ARR_SIZE = 5 };

/* The program's purpose is to declare and initialize an array of pointers
to integers, we use both the pointer notation and the subscript notation. */

int main(void) {
    int *array[ARR_SIZE];

    /* Subscript notation:
    Memory allocation and initilization for each array member */
    for (int i=0; i<ARR_SIZE; i++) {
        array[i] = malloc(sizeof(int));
        *array[i] = i*i;
    }

    return(EXIT_SUCCESS);
}
