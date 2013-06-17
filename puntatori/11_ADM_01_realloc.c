#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* Talvolta e' necessario incrementare o decrementare la memoria assegnata ad
un puntatore, la funzione predisposta a questo scopo e' realloc().

HEADER    : <stdlib.h>
PROTOTYPE : void *realloc(void *ptr, size_t size);
SEMANTICS : La funzione realloc() modifica il blocco di memoria puntato da 'ptr'
            al valore 'size'
RETURNS   : Un puntatore al nuovo blocco di memoria in caso di successo, NULL in
            caso di errore.
--------------------------------------------------------------------------------
- Se la richiesta di memoria sara' minore rispetto alla memoria correntemente
  allocata, quella in eccesso andra' sullo heap, senza però nessuna garanzia di
  pulizia;

- Se la richiesta di memoria sara' maggiore rispetto alla memoria correntemente
  allocata, sara' allocata la memoria necessaria partendo dalla locazione 
  successiva rispetto al blocco allocato, oppure la nuova memoria sara' allocata
  in una nuova regione sullo heap, copiando  il blocco vecchio;

- Se 'size' sara' 0 e il 'ptr' diverso da NULL, sara' equivalente a free(ptr);

- Se 'ptr' sara' NULL, la chiamata sara' equivalente a malloc(size);
*/

int main(int argc, char *argv[]) {
    /* Si provvede ad allocare delle stringhe */
    char *str1;
    char *str2;

    str1 = (char*) malloc(16);
    strcpy(str1, "0123456789AB");

    str2 = realloc(str1, 8);

    printf("str1 value: %p [%s]\n", str1, str1);
    printf("str2 value: %p [%s]\n", str2, str2);

    return(EXIT_SUCCESS);
}
