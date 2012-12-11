#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>


/* Un thread puo' essere cancellato da un altro thread all'interno dello stesso
processo:

HEADER    : <pthread.h>
PROTOTYPE : void pthread_cancel(pthread_t tid);
SEMANTICS : La funzione pthread_cancel() consente al thread corrente di 
            cancellare il thread indentificato da 'tid'.
RETURNS   : 0 in caso di successo, numero di errore in caso di errore
--------------------------------------------------------------------------------
Nota: E' come se fosse invocata la funzione pthread_exit(PTHREAD_CANCELED),
      inoltre la funzione pthread_cancel() non attende la terminazione del 
      thread, poiche' non si tratta di un vero e proprio 'ordine' ma piuttosto
      di una richiesta.
*/


int main(void) {
    
    return(EXIT_SUCCESS);
}
