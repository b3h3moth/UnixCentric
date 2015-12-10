#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(void) {
    unsigned long ulval = -1;

    if (ulval == UINT_MAX)
        printf("%lu = %u\n", ulval, UINT_MAX);
    else
        fputs("Err.\n", stdout);

    return(EXIT_SUCCESS);
}
