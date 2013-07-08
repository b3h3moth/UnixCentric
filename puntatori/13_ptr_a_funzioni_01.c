#include <stdio.h>
#include <stdlib.h>

#define MAX_MENU 3

/* Ogni funzione e' una voce del menu', accettano un argomento di tipo intero e
restituisce void. */
void voce1(int x);
void voce2(int y);
void voce3(int z);

/* I puntatori a funzione sono utilizzati spesso per fornire menu', all'interno
dei quali ciascuna opzione corrisponde ad una funzione, che peraltro sono
inserite in un vettore di puntatori a funzione. */

int main(void) {
    /* Inizializzazione di un vettore di 3 puntatori a funzione */
    void (*vec[MAX_MENU])(int) = {voce1, voce2, voce3};

    return(EXIT_SUCCESS);
}
