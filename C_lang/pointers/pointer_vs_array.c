#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float data[] = {1.1, 2.2, 3.3}, *ptr;
    
    ptr = &data[0]; 
    // Istruzione equivalente: ptr = data;

    printf(" address of the first element of the array data: data[0]\n");
    printf("        ptr: %p\n", (void *) ptr);
    printf("   &data[0]: %p\n", (void *) &data[0]);
    printf("       data: %p\n", (void *) data);

    printf("\n");

    printf("address of the second element of the array data: data[1]\n");
    printf("   (ptr +1): %p\n", (void *) (ptr + 1));
    printf("   &data[1]: %p\n", (void *) &data[1]);
    printf("  (data +1): %p\n", (void *) (data + 1));

    printf("\n");

    printf("value of the third element of the array data: data[2]\n");
    printf("  *(ptr +1): %f\n", *(ptr + 2));
    printf("*(&data[1]): %f\n", *(&data[2]));
    printf("  *(ptr +1): %f\n", *(data + 2));

    return(EXIT_SUCCESS);
}
