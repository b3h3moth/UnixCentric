#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 10

int main(void) {

    double numbers[MAX_ARR] = {
        [1] = 1.5,
        [3] = 1.E+2,
        [5] = 3.3,
        [7] = 800.98,
        [9] = 7890.9,
    };

    for (size_t i=0; i<MAX_ARR; i++) 
        printf("%zu:%g\n", i, numbers[i]);

    return(EXIT_SUCCESS);
}

/* Compile the program:

   $ c99 -Wall file.c -lm

*/
