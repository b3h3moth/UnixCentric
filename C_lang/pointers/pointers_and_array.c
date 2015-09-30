#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    
    // Due modalita' equivalenti per assegnare un array a un puntatore
    int *ptr_arr1 = data;     // 'data' contiene l'indirizzo del primo elemento
    int *ptr_arr2 = &data[0]; // Si rende esplicito il concetto sopra espresso

    /* Lo scostamento di seguito spostera' il puntatore avanti di 4 locazioni o
    indirizzi di memoria, ovvero 16 byte, poiche' si tratta di un 'int' a 
    32 bit (4 byte) */
    ptr_arr1 += 4;             // punta al quinto elemento dell'array
    printf("%d\n", *ptr_arr1); // Stampa il valore del quinto elemento

    /* Essendo 'data' un puntatore al primo elemento dell'array, e' possibile
    stampare o lavorare con l'i-esimo elemento dello stesso come fosse un
    puntatore */
    printf("%d\n", *(data + 8)); // Stampa il nono elemento dell'array

    // Stampare gli indirizzi di memoria, le seguenti istruzioni sono sinonimi
    printf("%p - %p\n", (void *)&data[4], (void *)(data +4));

    // Regola aurea: Puntatori ed array non sono la stessa cosa
    return(EXIT_SUCCESS);
}
