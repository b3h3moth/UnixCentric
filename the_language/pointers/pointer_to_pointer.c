#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number = 31337;
    int *ptr = &number;
    int **ptr_to_ptr = &ptr;

    printf("      address of number: %p\n", (void *)&number);
    printf("         *ptr points to: %p\n", (void *)ptr);
    printf(" **ptr_to_ptr points to: %p\n", (void *)*ptr_to_ptr);

    return(EXIT_SUCCESS);
}
