#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

int main(void) {
    int vector[SIZE];
    int *ptr;
    int i;

    /* Ciascun elemento dell'array, essendo un intero, ha una dimensione di 
    4 byte, per cui essendo l'array di dimensione SIZE, il totale della
    dimensione e' di 40 byte. */
    for (i=0; i<SIZE; i++)
        vector[i] = 100+i;

    printf("vector = 0x%lx\n", (unsigned long)vector);

    /* L'array creato altro non e' che un puntatore al suo primo elemento, per
    cui puo' essere assegnato ad un altro puntatore */
    ptr = vector;

    // Stampa indirizzi di memoria e valori del vettore
    for (i=0; i<SIZE; i++, ptr++) {
        printf("[%d] vector[%d]:%d <-> ptr(0x%lx):%d\n", \
                i, i,vector[i], (unsigned long) ptr, *ptr);
    }
    
    /* Da notare ptr-vector, in questo caso entra in gioco l'aritmetica dei
    puntatori, nello specifico si sta chiedendo il numero di elementi tra ptr e
    vector, che sarebbe in effetti la differenza dei due puntatori diviso la
    dimensione di un elemento, che nel caso specifico corrisponde a 4 byte. */

    return(EXIT_SUCCESS);
}

