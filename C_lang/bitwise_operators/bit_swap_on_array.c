#include <stdio.h>
#include <stdlib.h>

void bit_swap(int *x, int *y);
void reverse_array(int array[], int size);

int main(void) {

    return(EXIT_SUCCESS);
}

// Working with XOR and change each value
void bit_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}
