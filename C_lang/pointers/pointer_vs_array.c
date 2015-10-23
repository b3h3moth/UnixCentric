#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void) {
    float data[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5}, *ptr;
    
    ptr = &data[0]; 
    // Istruzione equivalente: ptr = data;

    printf(" address of the first element of the array data: data[0]\n");
    printf("       ptr: %p\n", (void *) ptr);
    printf("  &data[0]: %p\n", (void *) &data[0]);
    printf("      data: %p\n", (void *) data);

    printf("\n");

    printf("address of the second element of the array data: data[1]\n");
    printf("  (ptr +1): %p\n", (void *) (ptr +1));
    printf("  &data[1]: %p\n", (void *) &data[1]);
    printf(" (data +1): %p\n", (void *) (data +1));

    return(EXIT_SUCCESS);
}
