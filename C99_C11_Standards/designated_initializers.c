#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 10

int main(void) {

    int numbers[MAX_ARR] = {
        [1] = 100,
        [3] = 200,
        [5] = 600,
        [7] = 800,
        [9] = 1000,
    };

    for (int i=0; i<MAX_ARR; i++)
        fprintf (stdout, "%d\n", numbers[i]);

    return(EXIT_SUCCESS);
}

/* Compile the program:

   $ c99 -Wall file.c -lm

*/
