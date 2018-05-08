#include <stdio.h>
#include <stdlib.h>

#define VEC_SIZE(x)    (sizeof(x)/sizeof(x[0]))

int binary_search(int pattern, int vector[], int size);

/* La peculiarita' della ricerca binaria e' che elimina la meta' dei dati
ad ogni passo. */

int main(void) {
    int arr[] = {10, 12, 24, 21, 34, 37, 41, 48, 54, 59, 61, 68, 72, 77, 80,
                 85, 88, 91, 92, 94, 98, 100, 101, 102, 120, 130, 130, 178};
    int value = 72;

    int result = binary_search(value, arr, VEC_SIZE(arr));

    if (result == -1)
        printf("Element %d is not present\n", value);
    else
        printf("Element '%d' has index: '%d'\n", value, result);

    return(EXIT_SUCCESS);
}

int binary_search(int pattern, int vector[], int size) {
    int low, high, mid;

    low = 0;
    high = size;

    while (low <= high) {
        // Si dimezza la ricerca
        mid = (low + high) / 2;

        if (pattern < vector[mid])
            high = mid - 1;
        else if (pattern > vector[mid])
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}

