#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *ptr1, *ptr2;
    ptr1 = malloc(sizeof(int));
    
    *ptr1 = 1234;

    // Copia l'indirizzo della memoria allocata 
    ptr2 = ptr1;

    // Primo rilascio
    free(ptr1);

    /* Secondo rilascio, che tuttavia si riferisce al primo poiche' puntano
    alla medesima area di memoria, per cui vi sara' un errore non appena si
    provera' ad eseguire il programma - double free or corruption.
    */
    free(ptr2);
    
    return(EXIT_SUCCESS);
}
