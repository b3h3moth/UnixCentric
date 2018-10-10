#include <stdio.h>
#include <stdlib.h>

enum { ROW = 4, COL = 10 };

/* Lo scopo del sorgente e' di creare 'un array di puntatori a stringhe' e 
'un puntatore ad array di stringhe'. */

int main(void) {
    /* Stringhe da utilizzare con l'array di puntatori */
    char str1[] = "C Language";
    char str2[] = "C++ Language";
    char str3[] = "Perl Language";
    char str4[] = "Lisp Language";

    char *ptr1 = str1, *ptr2 = str2, *ptr3 = str3, *ptr4 = str4;

    // Array di puntatori
    char *arr[ROW] = {ptr1, ptr2, ptr3, ptr4};

    for (int i=0; i<ROW; i++)
        printf("> %s\n", arr[i]);

    /* Array bidimensionale, ciascuna riga corrisponde a una stringa, le 
    colonne invece indicano la lunghezza della stringa stessa */
    char marr[ROW][COL] = { "FreeBSD", "OpenBSD", "GNU/Linux", "Solaris" };

    // Puntatore ad array di stringhe - di dimensione massima COL.
    char (*ptrm)[COL] = marr;

    for (int i=0; i<ROW; i++)
        printf("- %s\n", *(ptrm + i) );
        // printf("- %s\n", ptrm[i] );  equivalente

    return(EXIT_SUCCESS);
}
/* Nota: Allorquando in C si parla di stringhe ci si riferisce sempre a un
         array di caratteri, per cui il puntatore a una stringa altro non e' 
         che un puntatore al primo carattere. */
