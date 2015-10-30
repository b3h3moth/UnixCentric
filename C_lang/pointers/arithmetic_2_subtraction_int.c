#include <stdio.h>
#include <stdlib.h>

// Array length
#define SIZE 10

int main(void) {
    // Sottrarre un intero a un puntatore
    int vec[SIZE] = {98, 16, 24, 10, 87, 28, 93, 11, 54, 92};
    int *ptr = &vec[SIZE-1];

    printf("            Array: ");
    for (int i=0; i<sizeof(vec)/sizeof(vec[0]); i++)
        printf("%d, ", vec[i]); 

    printf("\nAddress of vector: %d %p \n", *ptr, (void *)ptr);

    ptr--;                  /* 4 byte avanti */
    printf("ptr - %d (%2d byte): %d %p\n", 1, 4, *ptr, (void *)ptr);
    
    ptr -= 1;               /* 4 byte avanti */
    printf("ptr - %d (%2d byte): %d %p\n", 1, 4, *ptr, (void *)ptr);

    printf("ptr - %d (%2d byte): %d %p\n", 4, 16, *(ptr-4), (void *)(ptr-4));

    return(EXIT_SUCCESS);
}
