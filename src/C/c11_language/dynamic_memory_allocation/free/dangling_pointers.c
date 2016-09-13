#include <stdio.h>
#include <stdlib.h>

/* Dangling pointers; si verifica allorquando un puntatore referenzia della 
memoria gia' precedentemente rilasciata, per cui il puntatore stesso punta
a un oggetto non valido. */

int main(void) {
    int *ptr1, *ptr2;

    // Si alloca la memoria necessaria per contenere un dato intero
    ptr1 = malloc(sizeof(int));
    // Si assegna un valore intero all'area puntata
    *ptr1 = 100;
    // Un nuovo puntatore punta alla medesima area di memoria
    ptr2 = ptr1;
    // Rilascio della memoria, di entrambi poiche' ptr2 = ptr1
    free(ptr1); 
    // Dangling pointer; il nuovo puntatore tenta di assegnare un nuovo valore
    *ptr2 = 200;
    /* Da notare che potrebbe essere visualizzato il valore corretto, tuttavia 
    anche se cio' dovesse accadere si tratterebbe di un dato non valido */
    printf("ptr2 = %d\n", *ptr2);   


    int *ptr3;
    {
        // val e' allocata sullo stack
        int val = 300;
        ptr3 = &val;
        /* All'uscita dal blocco la variabile 'val' sara' estrapolata dallo 
        stack, ovvero cessera' di esistere. */
    }
    // per cui ptr3 adesso e' un Dangling Pointer.
    
    return(EXIT_SUCCESS);
}
