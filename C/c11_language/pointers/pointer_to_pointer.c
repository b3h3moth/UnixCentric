#include <stdio.h>
#include <stdlib.h>

// Lo scopo del programma e' la realizzazione di un puntatore a puntatore

int main(void) {
    int val = 100;
    /* La variabile puntatore 'ptr' contiene l'indirizzo di memoria della 
    variabile intera 'val' */
    int *ptr = &val;
    /* La variabile puntatore a puntatore 'pptr' contiene l'indirizzo della
    variabile puntatore 'ptr', che a sua volta punta a 'val', per cui 
    pptr punta a 'val'. */
    int **pptr = &ptr;

    printf("              Address of val: %p <-\n", (void*)&val);
    printf("              Address of ptr: %p <--\n", (void*)&ptr);
    printf("             Address of pptr: %p\n", (void*)&pptr);
    printf(" The address stored into ptr: %p <-\n", (void*)ptr);
    printf("The address stored into pptr: %p <--\n", (void*)pptr);
    printf("            The value of val: %d\n", val);
    printf("    The value pointed by ptr: %d\n", *ptr);
    printf("   The value pointed by pptr: %d\n", **pptr);

    return(EXIT_SUCCESS);
}
