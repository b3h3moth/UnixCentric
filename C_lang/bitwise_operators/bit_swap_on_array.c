#include <stdio.h>
#include <stdlib.h>

void bit_swap(int *x, int *y);

int main(void) {

    return(EXIT_SUCCESS);
}

// Working with XOR and change each value
void bit_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}
