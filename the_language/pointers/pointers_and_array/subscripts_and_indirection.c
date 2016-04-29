#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(void) {
    int arr[SIZE] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
    int *ap;

    // 'arr' e' un puntatore costante al primo elemento dell'array stesso.
    
    // Il puntatore ap punta al primo elemento dell'array 'arr'
    ap = arr;

    /* Se 'arr' e' un puntatore e' possibile utilizzare l'indirezione, stesso
    discorso naturalmente per il puntatore 'ap'. Nel caso specifico si
    utilizza l'indirezione per l'ottenimento di un Rvalue.*/
    printf("print element 1: %d\n", *(arr + 1));
    printf("print element 2: %d\n", *(ap + 2));

    // Modifca il valore di due elementi dell'array, mediante Lvalue
    *(arr + 2) = 2189;
    *(ap + 3) = 8768;

    /* Mediante il confronto tra puntatori, ovvero indirizzi, stampa ciascun
    elemento dell'array.  */
    puts("After indirection:");
    while (ap < &arr[SIZE]) {
        printf("%d, ", *ap);
        ap++;
    }

    return(EXIT_SUCCESS);
}
