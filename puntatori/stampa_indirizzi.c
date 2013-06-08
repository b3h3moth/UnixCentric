#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 0;
    int *ptr = &n;

    /* Per la stampa degli indirizzi e' consigliabile adoperare lo specificatore
    %p, in accoppiata con il cast del puntatore ad un puntatore a void, questo
    per rendere il codice eseguibile su diverse architetture. */

    printf("Address of n: %p - Value %d\n", (void *)&n, n);
    
    printf("Address of ptr: %p - Value %p\n", (void *)&ptr, (void *)ptr);

    return(EXIT_SUCCESS);
}
