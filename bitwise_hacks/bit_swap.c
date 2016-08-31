#include <stdio.h>
#include <stdlib.h>

void bit_swap(int *x, int *y);

int main(void) {
    int a = 10;
    int b = 20;

    printf("before swapping - a = %d, b = %d\n", a, b);
    bit_swap(&a, &b);
    printf(" after swapping - a = %d, b = %d\n", a, b);

    return(EXIT_SUCCESS);
}

// Working with XOR and change each value
void bit_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}
