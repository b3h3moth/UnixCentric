#include <stdio.h>
#include <stdlib.h>

#define MAX_MENU 3

/* Ogni funzione e' una voce del menu', accettano un argomento di tipo intero e
restituisce void. */
void voce1(int x);
void voce2(int x);
void voce3(int x);

/* I puntatori a funzione sono utilizzati spesso per fornire menu', all'interno
dei quali ciascuna opzione corrisponde ad una funzione, che peraltro sono
inserite in un vettore di puntatori a funzione. */

int main(void) {
    int choice;

    /* Inizializzazione di un vettore di 3 puntatori a funzione */
    void (*vec[MAX_MENU])(int) = {voce1, voce2, voce3};

    printf("> Menu'[0,1,2] (altro per uscire) ");
    scanf("%1d", &choice);

    while (choice >= 0 && choice <=2) {
        (*vec[choice])(choice);
        printf("> Menu'[0,1,2] - 3 per uscire: ");
        scanf("%1d", &choice);
    }

    return(EXIT_SUCCESS);
}
void voce1(int x)
{
    printf("voce1: %d\n", x);
}

void voce2(int x)
{
    printf("voce2: %d\n", x);
}

void voce3(int x)
{
    printf("voce3: %d\n", x);
}
