#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int data[][3] = {
        {10, 20, 30},
        {40, 50, 60},
    };

    // Puntano al primo elemento dell'array
    printf("    data: %p\n", (void *)data);
    printf("&data[0]: %p\n", (void *)&data[0]);

    return(EXIT_SUCCESS);
}
