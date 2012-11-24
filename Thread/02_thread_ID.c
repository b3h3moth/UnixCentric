#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/* Così come ciascun processo ha il proprio Process-ID, ciascun thread ha il
proprio Thread-ID, da notare tuttavia che il PID ha valenza nel contesto del
sistema - quindi ID di sistema -, mentre il TID ha valenza solo nell'ambito del
processo all'interno del quale il thread e' stato creato. Per ottenere il TID di
sistema e' necessario utilizzaare la funzione syscall(SYS_gettid).

Tipo di dato
------------
Anche i thread hanno il proprio tipo di dato, pthread_t, anch'esso, come pid_t
per i processi, e' un intero non negativo.

La funzione per ottenere l'ID del Thread e' pthread_self().

HEADER    : <pthread.h>
PROTOTYPE : pthread_t pthread_self(void);
SEMANTICS : 
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
