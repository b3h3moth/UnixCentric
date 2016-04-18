#include <stdio.h>
#include <stdlib.h>

enum { SIZE = 10 };

int main(void) {
    double arr[SIZE];
    double *ap;

    for (ap = &arr[0]; ap < &arr[SIZE]; ap++) {
        *ap = 1;
        printf("%g\n", *ap);
    }


    return(EXIT_SUCCESS);
}
