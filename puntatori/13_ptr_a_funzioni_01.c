#include <stdio.h>
#include <stdlib.h>

/* Ogni funzione e' una voce del menu', accettano un argomento di tipo intero e
restituisce void. */
void voce1(int x);
void voce2(int y);
void voce3(int z);

/* I puntatori a funzione sono utilizzati spesso per fornire menu', dove
ciascuna opzione del menu' corrisponde ad una funzione. Le funzioni sono
inserite in un vettore di puntatori a funzione. */

int main(void) {
    /* Inizializzazione di un vettore di 3 puntatori a funzione, ciascuna di 
    essere accetta un argomento di tipo intero e restituisce void
    return(EXIT_SUCCESS);
}
