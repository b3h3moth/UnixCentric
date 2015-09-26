#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Un puntatore e' un indirizzo e una variabile puntatore e' una variabile
    in grado di memorizzare un indirizzo o locazione di memoria.
    
    La grandezza di un puntatore dipende dall'architettura della macchina 
    (32bit, 64bit) e di conseguenza dal tipo di dato con cui e' stato 
    dichiarato.  */
    int n = 0;
    int *ptr = &n; /* ptr e' una variabile puntatore in grado di puntare ad
                      oggetti di tipo intero */
                        

    printf("*ptr is %d byte\n", sizeof(ptr));

    /* Nota: E' buona norma leggere le dichiarazioni di puntatori da destra a
    sinistra. */

    return(EXIT_SUCCESS);
}
