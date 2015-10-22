#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number = 100;
    int *ptr = &number;
    int **ptr_to_ptr = &ptr;

    printf("address of number: %p\n", &number);
    printf("address of number: %p\n", ptr);
    printf("address of number: %p\n", *ptr_to_ptr);

    return(EXIT_SUCCESS);
}
