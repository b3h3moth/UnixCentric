#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int val1 = 567;
    int val2 = 987;

    int result = val2 ^ ((val1 ^ val2) & -(val1 < val2));

    printf("The minimum of %d and %d is: %d\n", val1, val2, result);

    return(EXIT_SUCCESS);
}
