#include <stdio.h>
#include <stdlib.h>

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

    printf("%d %p <-- indirizzo iniziale del vettore\n", *ptr, ptr);
    ptr++;                  /* 4 byte avanti */
    printf("%d %p\n", *ptr, ptr);
    ptr += 1;               /* 4 byte avanti */
    printf("%d %p\n", *ptr, ptr);

  
    int v[] = {1,2,3};
    int *p = v;
    p += 3; /* Il puntatore ora punta a se stesso */
    printf("\n%p v[3]\n%p p", &v[3], p);

    /* Sottrarre un intero da un puntatore 
       -----------------------------------*/
    printf("\n\nSottrazione tra intero e puntatore\n");
    int vect[] = {12, 56, 78};
    int *pt = vect + 2; /* Si fa puntatore all'ultimo elemento del vettore */

    printf("%d\n", *pt);
    pt--;                   /* 4 byte indietro */
    printf("%d\n", *pt);
    pt -= 1;                /* 4 byte indietro */
    printf("%d\n", *pt);

    /* Sottrarre puntatore a puntatore 
       -------------------------------*/
    printf("\n\nSottrazione  puntatori\n");
    int *pt0 = vect;
    int *pt1 = vect + 1;
    int *pt2 = vect + 2;

    printf("%d\n%d\n%d\n", pt2-pt0, pt2-pt1, pt0-pt1);

    /* Confronto tra punatori 
       ---------------------- 
    Si lavora sul confronto tra gli indici dell'array - 0 false, 1 true */
    printf("\nConfronto tra puntatori\n");
    printf("pt0 > pt1 : %d\n", pt0 > pt1);
    printf("pt0 < pt1 : %d\n", pt0 < pt1);
    printf("pt2 > pt1 : %d\n", pt2 > pt1);
    printf("pt2 < pt1 : %d\n", pt2 < pt1);
    printf("pt0 > pt2 : %d\n", pt0 > pt1);
    printf("pt0 < pt2 : %d\n", pt0 < pt1);

    return(EXIT_SUCCESS);
}
