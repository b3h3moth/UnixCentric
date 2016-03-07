#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Inizializzazione del puntatore 'ptr' al primo elemento dell'array
    int *ptr = (int []){10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    while(*ptr > 0) {
        printf("%3d\n", *ptr);
        ptr++;
    }

    return(EXIT_SUCCESS);
}
