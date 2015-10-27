#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int val1 = INT_MIN;

    if ( (val1 > 0) || (val1 -1 < 0) )
        printf("true\n");
    else
        printf("false; %d - 1 = %d\n", INT_MIN, INT_MIN-1); // integer overflow

    if ( (val1 & 7) != 7 || (val1<<29 < 0) )
        printf("true\n");
    return(EXIT_SUCCESS);
}
