#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int val1 = 229;
    int val2 = 281;

    int result = val1 ^ ((val1 ^ val2) & -(val1 < val2));

    printf("The maximum of %d and %d is: %d\n", val1, val2, result);

    return(EXIT_SUCCESS);
}
