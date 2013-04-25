#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

/* Allorquando si lavora con thread multipli si possono verificare dei casi in
cui alcuni di essi condividano la stessa variabile, ed e' proprio in tali 
contesti che la gestione della consistenza dei dati e' fondamentale.

Cos'e' la consistenza dei dati? Poniamo il caso di avere due thread che 
condividono la stessa variabile in sola lettura, in questo specifico ambito vi 
e' consistenza poiche' nessuno dei due thread puo' modificare la variabile; se
invece uno dei due thread avesse accesso alla variabile anche in scrittura e 
dovesse modificarne il valore, la variabile stessa si troverebbe in uno stato 
inconsistente, perche' il thread in sola lettura leggerebbe prima un valore e 
poi un altro. Vi dev'essere coerenza per ciascun thread.

Per risolvere il problema si deve disporre di un meccanismo di lock, che
consenta ad un thread per volta l'accesso alla variabile, in pratica vi deve
essere sincronizzazione.

La gestione della consistenza dei dati e' fondamentale

HEADER    : 
PROTOTYPE : 
SEMANTICS : 
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
