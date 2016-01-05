#include <stdio.h>
#include <stdlib.h>

/* Compound literals (Letterali composti)

Un letterale composto viene creato all'occorrenza, ovvero specificando soltanto
gli elementi che dovra' contenere.

Si realizza con:
- Il tipo di dato tra parentesi tonde seguito o meno dal numero di elementi del
  vettore;
- All'interno di parentesi graffe l'inizializzazione.

E' lecito utilizzare 'const' per avere un array in sola lettura.
*/

int sum(const int vec[], int size);

int main(void) {
    /* Creazione di un letterale composto senza specificare il numero di 
    elementi del vettore */
    int tot   = sum( (int []){1,2,3,4,5}, 5);

    /* Creazione di un letterale composto specificando il numero di 
    elementi del vettore */
    int total = sum( (const int [5]){1,2,3,4,5}, 5);

    printf("  tot: %d\n", tot);
    printf("total: %d\n", total);

    return(EXIT_SUCCESS);
}

int sum(const int vec[], int size) {
    int tmp = 0;

    for (int i=0; i<size; i++)
        tmp += vec[i];

    return tmp;
}

/* Un Compound literal fa pensare ai tipi di dato anonimi del Perl.
Al momento trovano una collocazione come argomenti di funzione. */
