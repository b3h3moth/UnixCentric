#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* I compilatori riscrivono l'accesso a un array mediante puntatori, ma
    attenzione, puntatori e array non sono la stessa cosa.
    
    arr[i]    e' sempre riscritto come:   *(val + i)
    arr[i][j] e' sempre riscritto come: *(*(val + i) + j)
    */

    int val[] = {1,2,3,4,5,6,7,8,9,10};

    for (int i=0; i<sizeof(val)/sizeof(val[0]); i++)
        printf("%2d ", *(val + i));

    puts(" ");

    int matrix[2][5] = {{11,12,13,14,15},{16,17,18,19,20}};

    for (int i=0; i<2; i++) 
        for (int j=0; j<5; j++)
            printf("%2d ",  *(*(matrix + i)+j) );

    return(EXIT_SUCCESS);
}
