#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 10

int main(void) {

    int numbers[MAX_ARR] = {
        [1] = 1.5,
        [3] = 20,
        [5] = 4.E+21,
        [7] = 800,
        [9] = .82370,
    };

    for (size_t i=0; i<MAX_ARR; i++)
        printf("elem: %d\n", numbers[i]);

    return(EXIT_SUCCESS);
}

/* Compile the program:

   $ c99 -Wall file.c -lm

*/
