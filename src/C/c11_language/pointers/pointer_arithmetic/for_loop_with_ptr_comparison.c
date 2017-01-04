#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int vec[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900 };
    int *ptr;

    for (ptr = vec; ptr <= vec+8; ptr++)
        printf("%d, ", *ptr);

    return(EXIT_SUCCESS);
}
