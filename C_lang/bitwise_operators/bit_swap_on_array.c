#include <stdio.h>
#include <stdlib.h>

#define EVEN_SIZE 10    // Array con un numero pari di elementi
#define ODD_SIZE   9    // Array con un numero dispari di elementi

void bit_swap(int *x, int *y);
void reverse_array(int array[], int size);

/* Lo scopo del programma e' di verificare il diverso risultato, rispetto a cio'
che ci si aspetterebbe, nell'invocare la funzione reverse_array() con un numero
di elementi prima pari poi dispari */

int main(void) {
    int numbers_a[EVEN_SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int  numbers_b[ODD_SIZE] = {1,2,3,4,5,6,7,8,9};

    printf("Call function with EVEN_SIZE number of elements\n");
    reverse_array(numbers_a, EVEN_SIZE);

    for (int i=0; i<EVEN_SIZE; i++)
        printf("%d ", numbers_a[i]);

    printf("\n\nCall function with ODD_SIZE number of elements\n");
    reverse_array(numbers_b, ODD_SIZE);

    for (int y=0; y<ODD_SIZE; y++)
        printf("%d ", numbers_b[y]);

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
