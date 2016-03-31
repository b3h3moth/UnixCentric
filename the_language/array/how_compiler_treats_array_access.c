#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* I compilatori riscrivono l'accesso a un array mediante puntatori, ma
    attenzione, puntatori e array non sono la stessa cosa.
    
    val[i] e' sempre riscritto come *(val + i)
    val[i][j] e' sempre riscritto come *(val + i) + j)
    */

    return(EXIT_SUCCESS);
}
