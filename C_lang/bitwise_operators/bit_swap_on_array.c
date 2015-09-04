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

void reverse_array(int array[], int size) {
    int first, last;

    for (first = 0, last = size -1; first <= last; first++, last--)
        bit_swap(&array[first], &array[last]);
}
