#include <stdio.h>
#include <stdlib.h>

enum { ARR_SIZE = 5 };

/* The program's purpose is to declare and initialize an array of pointers
to integers with dereference and subscript notations. */

int main(void) {
    int *array[ARR_SIZE];
    int *arr[ARR_SIZE];

    // Memory allocation and initilization for each array member
    
    // Subscript notation
    for (int i=0; i<ARR_SIZE; i++) {
        array[i] = malloc(sizeof(int));
        *array[i] = i*i;
    }

    // Dereferencing
    for (int i=0; i<ARR_SIZE; i++) {
        *(arr + i) = malloc(sizeof(int));
        **(arr + i) = i+i;
    }

    return(EXIT_SUCCESS);
}
