#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Inizializzazione del puntatore 'ptr' al primo elemento dell'array
    int *ptr = (int []){10, 20, 30, 40, 50};

    printf("%d\n", *(ptr + 4));

    return(EXIT_SUCCESS);
}
