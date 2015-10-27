#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int val1 = INT_MIN;

    if (val1 > 0) || (val1 -1 < 0)
        printf("true\n");
    else
        printf("false\n");
    return(EXIT_SUCCESS);
}
