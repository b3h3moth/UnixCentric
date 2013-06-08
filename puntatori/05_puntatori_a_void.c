#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Un puntatore a void e' un puntatore utilizzato per contenere riferimenti
    ad altri tipi di dato; qualsiasi puntatore puo' essere assegnato ad un 
    puntatore a void, gode peraltro della stessa rappresentazione e del medesimo
    allineamento in memoria di un puntatore a char.
    */

    int n = 10;
    int *ptr = &n;

    printf(" Valore di ptr: %p\n", ptr);

    /* Al puntatore a void vptr si assegna il puntatore ad intero ptr */
    void *vptr = ptr;

    /* Si casta per tornare (indietro) al valore del puntatore originale */
    ptr = (int *)vptr;

    printf(" Valore di ptr: %p\n", ptr);
    
    /* La dereferenziazione non e' consentita, in caso di compilazione ci sara'
    un errore del compilatore:

    printf("Valore di vptr: %p\n", *vptr);
                                   
    warning: dereferencing ‘void *’ pointer [enabled by default]
    error: invalid use of void expression
    */

    return(EXIT_SUCCESS);
}
