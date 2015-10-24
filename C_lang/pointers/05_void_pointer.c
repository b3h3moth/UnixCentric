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
    int *p;

    printf("   n: %p\n", (void *)&n);
    printf(" ptr: %p\n", (void *)ptr);

    /* Al puntatore a void vptr si assegna il puntatore ad intero ptr */
    void *vptr = ptr;

    printf("vptr: %p\n", vptr);
    
    /* printf(" Valore di ptr: %d\n", *vptr);
    
    La dereferenziazione non e' consentita, in caso di compilazione ci sara'
    un errore del compilatore, 'error: invalid use of void expression'.
    */

    p = vptr;

    printf("   p: %p\n", (void *)p);
    printf("   p: %d\n", *p);

    return(EXIT_SUCCESS);
}
