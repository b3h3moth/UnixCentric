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
- Se la richiesta di memoria fosse minore rispetto alla memoria correntemente
  allocata, quella in eccesso sarebbe restituita allo heap, senza però nessuna 
  garanzia di pulizia, ossia il contenuto delle locazioni di memoria 
  resterebbe immutato;

- Se la richiesta di memoria fosse maggiore rispetto alla memoria correntemente
  allocata, sarebbe allocata la memoria necessaria partendo dalla locazione 
  successiva rispetto al blocco allocato, oppure la nuova memoria sarebbe 
  allocata in una nuova regione sullo heap, copiando il blocco vecchio;

- Se 'size' vale 0 e 'ptr' diverso da NULL, sara' equivalente a free(ptr);
- Se 'ptr' vale NULL, la chiamata sara' equivalente a malloc(size).
*/

int main(int argc, char *argv[]) {
    /* richiesta di memoria minore rispetto alla memoria correntemente 
    allocata */
    char *email;
    char *backup;

    /* Si allocano 30 byte ma se ne utilizzano solo 23 */
    email = (char*) malloc(30);
    strcpy(email, "behemoth@autistici.org");   /* 23 byte compreso '\0' */

    /* Si allocano solo 15 byte */
    backup = realloc(email, 15);

    /* Come si potra' evincere dall'output, sara' riutilizzato il blocco
    originario contenuto compreso non modificato, la stringa inoltre sara' ben
    maggiore di 15 byte */
    printf("e-mail value: %p [%s]\n", email, email);
    printf("backup value: %p [%s]\n", backup, backup);

    return(EXIT_SUCCESS);
}
