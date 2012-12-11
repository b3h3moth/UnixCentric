#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

/* Un thread puo' predisporre la chiamata di talune funzioni alla chiusura del 
thread stesso, il funzionamento e' molto simile alla funzione atexit[1]; tali
funzioni sono chiamate "thread cleanup handlers", sono collocate sullo stack
per cui saranno eseguite in ordine inverso rispetto alla collocazione.

HEADER    : <pthread.h>
PROTOTYPE : void pthread_cleanup_push(void (*routine)(void*), void *arg);
            void pthread_cleanup_pop(int execute);
SEMANTICS : La funzione pthread_cleanup_push() registra la funzione di cleanup
            'routine' che sara' invocata con argomento 'arg' in seguito a:
            1 - una chiamata alla funzione pthread_exit();
            2 - come risposta ad una richiesta di cancellazione;
            3 - una chiamata a pthread_cleanup_pop(), con argomento non zero,
                nel caso specifico 'execute'.

RETURNS   : Questa funzione non ritorna
--------------------------------------------------------------------------------
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
