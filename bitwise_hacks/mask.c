#include <stdio.h>
#include <stdlib.h>

#define LEN 10

int main(void) {
    /* Una maschera e' una costante o una variabile, e' utilizzata per estrarre
    i bit desiderati da una variabile o da un'espressione */

    int mask = 1; // 00000000 00000000 00000000 00000001

    // Si utilizza la maschera per determinare il bit meno significativo
    for (int i=0; i<LEN; i++)
        printf("%d & mask(%d) = %d\n", i, mask, i & mask);

    return(EXIT_SUCCESS);
}
