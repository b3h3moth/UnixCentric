#include <stdio.h>
#include <stdlib.h>

#define EVEN_SIZE 10    // Array con un numero pari di elementi
#define ODD_SIZE   9    // Array con un numero dispari di elementi

void bit_swap(int *x, int *y);
void reverse_array(int array[], int size);

int main(void) {
    int my_array[5] = {1,2,3,4,5};

    reverse_array(my_array, 5);

    for (int i=0; i<5; i++)
        printf("%d ", my_array[i]);

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
