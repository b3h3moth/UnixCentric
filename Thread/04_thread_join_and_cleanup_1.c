#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

/* 
HEADER    : <pthread.h>
PROTOTYPE : int pthread_join(pthread_t thread, void **retval);
SEMANTICS : La funzione pthread_join() attende la terminazione del thread 
            specificato dal primo argomento 'thread', in retval sara' salvato
            il valore di ritorno del thread terminato.
RETURNS   : 0 in caso di successo, numero di errore in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[], char *envp[]) {
    pthread_t thrID;
    int err;
    
    err = pthread_create(&thrID, NULL, &print, NULL);


   return(EXIT_SUCCESS);
}
