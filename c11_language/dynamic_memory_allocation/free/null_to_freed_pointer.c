#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float *ptr;
    
    /* Alloca la memoria per contenere un tipo di dato floatero */
    ptr = malloc(sizeof(float));
    
    /* Lo spazio di memoria viene ora rilasciato */
    free(ptr);

    /* Nessun cambiamento nel programma */
    free(NULL);

    /* Si assegna NULL al puntatore rilasciato per evitare comportamenti
    indefiniti in futuro. E' una buona tecnica di programmazione 
    conservativa. */
    ptr = NULL;

    return(EXIT_SUCCESS);
}
