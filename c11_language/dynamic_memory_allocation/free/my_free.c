#include <stdio.h>
#include <stdlib.h>

// Function Prototype
void my_free(void **pptr);

/* Lo scopo del programma e' di scrivere una nuova funzione free() seguendo
specifici accorgimenti legati alla sicurezza */

int main(void) {
    int val = 10;
    int *pv = malloc(sizeof(int));
    *pv = 100;

    printf("%d\n", *pv);
    my_free((void **)&pv);

    return(EXIT_SUCCESS);
}

void my_free(void **pptr) {
    if (pptr != NULL && *pptr != NULL) {
        free(*pptr);
        *pptr = NULL;
    }
}
