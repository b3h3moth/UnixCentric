#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void) {
    float data[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5}, *ptr;
    
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

    printf("\n");

    /* Sebbene l'elemento data[SIZE] non esista - gli elementi del vettore
    sono SIZE-1 - e' perfettamente lecito e anche sicuro utilizzare
    ptr1 < &data[SIZE] */
    
    float *ptr1;

    for (ptr1 = &data[0]; ptr1 < &data[SIZE]; ptr1++)
        printf("%.1f, ", *ptr1);
    
    printf("\n");
    
    // Ancor piu' efficiente

    ptr1 = &data[0];

    while (ptr1 < &data[SIZE])
        printf("%.1f, ", *ptr1++);

    return(EXIT_SUCCESS);
}
