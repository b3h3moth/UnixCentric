#include <stdio.h>
#include <stdlib.h>

void foo(int *ptr);

int main(void) {
    /* In C il passaggio dei parametri avviene sempre per valore, poi se per
    mezzo dei puntatori tale regola possa essere aggirata o meno e' un altro 
    discorso. */
    int num = 20;
    int *p = &num;

    /* Lo specificatore di formato %p stampa l'indirizzo di memoria del
    puntatore in formato esadecimale. */
    printf("Address before foo() function: %p: %d\n", (void *)p, *p);

    foo(p);

    printf(" Address after foo() function: %p: %d\n", (void *)p, *p);

    /* In entrambi i casi la printf() ha visualizzato il medesimo indirizzo,
    pertanto il passaggio dei parametri e' per value, anche se si tratta di
    puntatori, in queso caso */

    return(EXIT_SUCCESS);
}

void foo(int *ptr) {
    int val = 10;
    ptr = &val;
    printf("Address of 'ptr' inside foo(): %p: %d\n", (void *)ptr, *ptr);
}
