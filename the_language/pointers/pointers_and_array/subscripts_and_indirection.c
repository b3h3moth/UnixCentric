#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(void) {
    int arr[SIZE] = {0,1,2,3,4,5,6,7,8,9};
    int *ap;

    // 'arr' e' un puntatore costante al primo elemento dell'array stesso.
    
    // Il puntatore ap punta al primo elemento dell'array 'arr'
    ap = arr;

    /* Se 'arr' e' un puntatore e' possibile utilizzare l'indirezione, stesso
    discorso naturalmente per il puntatore 'ap'. Nel caso specifico si
    utilizza l'indirezione per l'ottenimento di un Rvalue.*/
    printf("%d\n", *(arr + 1));
    printf("%d\n", *(ap + 1));

    return(EXIT_SUCCESS);
}
