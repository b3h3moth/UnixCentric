#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* The purpose of this program is to find the sign of a number, the result 
goes into 'result' variable.
Positive is +1, Negative is -1 */

int main(void) {
    int value = -378;
    int result = +1 | (value >> (sizeof(int) * CHAR_BIT - 1));

    printf("%d\n", result);

    return(EXIT_SUCCESS);
}
