#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* I compilatori riscrivono l'accesso a un array mediante puntatori, ma
    attenzione, puntatori e array non sono la stessa cosa.
    
    val[i] e' sempre riscritto come *(val + i)
    val[i][j] e' sempre riscritto come *(val + i) + j)
    */

    int val[] = {1,2,3,4,5,6,7,8,9,10};

    for (int i=0; i<sizeof(val)/sizeof(val[0]); i++)
        printf("%d, ", *(val + i));

    return(EXIT_SUCCESS);
}
