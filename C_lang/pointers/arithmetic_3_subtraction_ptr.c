#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Array length
#define SIZE 10
    
// Sottrazione di un puntatore da un puntatore

int main(void) {
    int vec[SIZE] = {98, 16, 24, 10, 87, 28, 93, 11, 54, 92};
    // Si fa puntare il puntatore all'ultimo elemento del vettore
    int *ptr0 = &vec[SIZE-1];
    // Si fa puntare il puntatore all'elemento 6 del vettore
    int *ptr1 = &vec[5];
    // Si fa puntare il puntatore all'elemento 2 del vettore
    int *ptr2 = &vec[1];

    /* Il tipo di dato da utilizzare per la differenza tra puntatori si
    esprime mediante il tipo 'ptrdiff_t' definito in <stddef.h>;
    lo specificatore di formato associabile e' %td */
    ptrdiff_t res1 = ptr0 - ptr1;
    ptrdiff_t res2 = ptr1 - ptr2;

    printf("             Array: ");
    for (int i=0; i<sizeof(vec)/sizeof(vec[0]); i++)
        printf("%d, ", vec[i]); 

    printf("\n   Address of ptr0: %d %p \n", *ptr0, (void *)ptr0);
    printf("   Address of ptr1: %d %p \n", *ptr1, (void *)ptr1);
    printf("   Address of ptr2: %d %p \n", *ptr2, (void *)ptr2);

    printf("       ptr0 - ptr1: %td\n", res1);
    printf("       ptr1 - ptr2: %td\n", res2);

    // Sottrazione di due puntatori all'interno dell'operatore subscript
    int *ptr4 = &vec[ptr0 - ptr1];

    printf("array[ptr0 - ptr1]: %d %p\n", *ptr4, (void *)ptr4);

    return(EXIT_SUCCESS);
}
