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
Nota: E' come se fosse invocata la funzione pthread_exit(PTHREAD_CANCELED);
*/

void *thr_func(void *thr_num);

int main(void) {
    pthread_t thr[MAX_THREAD];
    int i, thr_err;

    /* Si provvede alla creazione di MAX_THREAD thread */
    for (i=0; i<MAX_THREAD; i++) {
        
        if ((thr_err = pthread_create(&thr[i],NULL, thr_func, (void*)i)) != 0) {
            fprintf(stderr, "Err. pthread_create() %s\n", strerror(thr_err));
            exit(EXIT_FAILURE);
        }
    }

    for (i=0; i<MAX_THREAD; i++) {
        if (pthread_join(thr[i], NULL) != 0) {
            fprintf(stderr, "Err. pthread_join() %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
    
    return(EXIT_SUCCESS);
}

void *thr_func(void *thr_num)
{
    pthread_t tid;

    if ((tid = syscall(SYS_gettid)) == -1) { 
        fprintf(stderr, "Err. syscall() %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("thread '%d' - TID %lu - Address 0x%x\n", 
            (int)thr_num, tid, (unsigned int)tid);

    /* La funzione pthread_exit() termina il thread chiamante */
    pthread_exit((void*)0);
}
