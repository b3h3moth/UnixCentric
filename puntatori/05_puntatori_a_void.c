#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Un puntatore a void e' un puntatore utilizzato per contenere riferimenti
    ad altri tipi di dato; qualsiasi puntatore puo' essere assegnato ad un 
    puntatore a void.
    
    Gode di caratteristiche peculiari:
    - gode della stessa rappresentazione e allineamento in memoria di un 
      puntatore a char.
    */

    int n;
    int *ptr = &n;

    printf(" Valore di ptr: %p\n", ptr);

    /* Al puntatore a void vptr si assegna il puntatore ad intero ptr */
    void *vptr = ptr;

    /* Si casta per tornare (indietro) al valore del puntatore originale */
    ptr = (int *)vptr;

    printf(" Valore di ptr: %p\n", ptr);
    printf("Valore di vptr: %p\n", vptr);

    return(EXIT_SUCCESS);
}
