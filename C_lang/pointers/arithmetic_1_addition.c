#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(int argc, char *argv[]) {
    /* Quando si lavora con l'aritmetica dei puntatori si deve sempre tenere a
    mente la grandezza di ciascun tipo di dato:
    
    char    1 byte
    short   2 byte 
    int     4 byte
    long    8 byte
    float   4 byte
    double  8 byte

    Le operazioni permesse sono:
    - La somma di un intero a un puntatore;
    - La sottrazione da un puntatore di un intero;
    - La sottrazione da un puntatore di un puntatore.

    Inoltre vi e' anche il confronto tra puntatori mediante gli operatori
    relazionali, ma non e' un'operazione aritmetica in senso stretto.
    */

    // Sommare un intero a un puntatore 
    printf("Somma\n");
    int vec[] = {98, 16, 24};
    int *ptr = vec; /* Non serve l'operatore di indirizzo perche' in questo
                       caso il puntatore puntera' all'inizio del vettore,
                       ossia al primo elemento */

    printf("%d %p <-- indirizzo iniziale del vettore\n", *ptr, (void *)ptr);
    ptr++;                  /* 4 byte avanti */
    printf("%d %p\n", *ptr, (void *)ptr);
    ptr += 1;               /* 4 byte avanti */
    printf("%d %p\n", *ptr, (void *)ptr);

  
    int v[] = {1,2,3};
    int *p = v;
    p += 3; /* Il puntatore ora punta a se stesso */
    printf("\n%p v[3]\n%p p\n", (void *)&v[3], (void *)p);

    return(EXIT_SUCCESS);
}
