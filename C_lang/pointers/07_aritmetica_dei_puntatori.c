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
    */

    /* Sommare un intero a un puntatore 
       --------------------------------*/
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

    /* Sottrarre un intero da un puntatore 
       -----------------------------------*/
    printf("Sottrazione tra intero e puntatore\n");
    int vect[] = {12, 56, 78};
    int *pt = vect + 2; /* Si fa puntatore all'ultimo elemento del vettore */

    printf("%d\n", *pt);
    pt--;                   /* 4 byte indietro */
    printf("%d\n", *pt);
    pt -= 1;                /* 4 byte indietro */
    printf("%d\n", *pt);

    /* Sottrarre puntatore a puntatore 
       -------------------------------*/
    printf("Sottrazione  puntatori\n");
    int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *pt0 = &data[2];
    int *pt1 = &data[4];
    int *pt2 = &data[6];

    /* Il tipo di dato per esprimere la differenza tra puntatori si esprime 
    con ptrdiff_t definito in <stddef.h> e lo specificatpre di formato
    utilizzabile mediante la printf() e' %td */
    ptrdiff_t res1 = pt0 - pt1;
    ptrdiff_t res2 = pt2 - pt0;
    printf("%td\t%td\n", res1, res2);

    /* Confronto tra punatori 
       ---------------------- 
    Il confronto avviene tra indirizzi di memoria, 0 false, 1 true */
    printf("\nConfronto tra puntatori\n");
    printf("[%p] > [%p] = %d\n", (void *)pt0, (void *)pt1, pt0 > pt1);
    printf("[%p] < [%p] = %d\n", (void *)pt0, (void *)pt1, pt0 < pt1);
    printf("[%p] > [%p] = %d\n", (void *)pt1, (void *)pt2, pt1 > pt2);
    printf("[%p] < [%p] = %d\n", (void *)pt1, (void *)pt2, pt1 < pt2);
    printf("[%p] == [%p] = %d\n", (void *)pt1, (void *)(pt2-2), pt1 < pt2-2);

    // Utilizzo del tipo di dato _Bool per salvare il risultato del contronto
    _Bool result1 = (pt0 == pt2);
    _Bool result2 = (pt0 == pt2-4);

    printf("result1 = %d\n", result1);
    printf("result2 = %d\n", result2);

    return(EXIT_SUCCESS);
}
