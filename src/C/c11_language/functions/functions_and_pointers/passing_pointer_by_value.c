#include <stdio.h>
#include <stdlib.h>

void foo(int *ptr);

int main(void) {
    /* In C il passaggio dei parametri avviene sempre per valore - by value -, 
    tuttavia se per mezzo dei puntatori tale regola possa essere aggirata
    fornendo un'illusoria parvenza di passaggio per riferimento - by reference -
    e' tutt'altro discorso, cio' che non cambia e' il dato incontrovertibile
    che nel linguaggio C il passaggio dei parametri avviene by value. */
    int num = 20;
    int *p = &num;

    // Stampa l'indirizzo della variabile 'num' puntata da 'p'
    printf("Address before foo() function: %p: %d\n", (void *)p, *p);

    foo(p);

    // Stampa l'indirizzo della variabile 'num' puntata da 'p'
    printf(" Address after foo() function: %p: %d\n", (void *)p, *p);

    /* In entrambi i casi la printf() ha visualizzato il medesimo indirizzo,
    pertanto il passaggio dei parametri e' per value, anche se si tratta di
    puntatori, in queso caso */

    return(EXIT_SUCCESS);
}

void foo(int *ptr) {
    /* Al puntatore 'ptr' si assegna l'indirizzo della variabile 'val', 
    inoltre si modifica il valore della variabile stessa; tali istruzioni 
    non riguardano ne' il valore di 'num' ne' tantomento il suo indirizzo, 
    dimostrando il fatto che il passaggio dei parametri avviene by value. */
    int val = 10;
    ptr = &val;
    *ptr = 30;

    // Stampa l'indirizzo della variabile 'val' puntata da 'ptr'
    printf("Address of 'ptr' inside foo(): %p: %d\n", (void *)ptr, *ptr);
}
