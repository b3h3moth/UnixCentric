#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 10;

int main(void) {

    int numbers[MAX_ARR] = {
        [0] = 100,
        [2] = 200,
        [4] = 600,
        [8] = 800,
        [9] = 1000,
    };

    for (int i=0; i<MAX_ARR; i++)
        fprintf (stdout, "%d\n", numbers[i]);

    return(EXIT_SUCCESS);
}
