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

void *thr_func(void *arg);

int main(void) {
    pthread_t thrID1, thrID2;
    int thr_err;
    
    
    if ((thr_err = pthread_create(&thrID1,NULL, thr_func, NULL)) != 0) {
        fprintf(stderr, "Err. pthread_create()  %s\n", strerror(thr_err));
        exit(EXIT_FAILURE);
    }

    pthread_cancel(thrID1);
    
    if (pthread_join(thrID1, NULL) != 0) {
        fprintf(stderr, "Err. pthread_join() %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    return(EXIT_SUCCESS);
}

void *thr_func(void *arg)
{
    pthread_t tid;

    if ((tid = syscall(SYS_gettid)) == -1) { 
        fprintf(stderr, "Err. syscall() %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("thread TID %lu \n", (unsigned int)tid);

}
