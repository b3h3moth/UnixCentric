#include <stdio.h>
#include <stdlib.h>

/* Dangling pointers; si verifica allorquando un puntatore referenzia della 
memoria gia' precedentemente rilasciata. */

int main(void) {
    int *p1, *p2;
    p1 = (int*) malloc(sizeof(int));
    *p1 = 100;
    p2 = p1;
    free(p1); /* Si rilascia la memoria ... di entrambi, poiche' p2 = p1 */
    *p2 = 100; /* Dangling pointer */
    printf("p2 = %d\n", *p2);   /* Potrebbe anche essere visualizzato il valore
                                   corretto, tuttavia resta comunque un dato
                                   non conforme */

    return(EXIT_SUCCESS);
}
