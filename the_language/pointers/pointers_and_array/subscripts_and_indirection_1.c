#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(void) {
    // 'arr' e' un puntatore costante al primo elemento dell'array stesso.
    int arr[SIZE] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
    int *ap;

    // Il puntatore ap punta al primo elemento dell'array 'arr'
    ap = arr;

    /* La dichiarazione dell'array 'arr' riserva spazio in memoria per il
    numero degli elementi dell'array. La dichiarazione del puntatore invece
    riserva spazio solo per il puntatore stesso.

    *arr    e' lecita, si ottiene un Rvalue, ovvero il primo elemento. 
    *ap     non e' lecita poiche' non si sa a cosa punti. */
    printf("get first element: %d\n", *arr);

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
