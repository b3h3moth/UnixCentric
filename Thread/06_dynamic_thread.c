#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

/* variabile globale condivisa tra i thread */
int global_var = 10;

void *thr_func(void *thr_num);

/* Il programma riceve come argomento il numero di thread da creare
dinamicamente. */
int main(int argc, char *argv[]) {
    int i, thr_err, n_thr;

    if (argc != 2) {
        fprintf(stderr, "Uso: %s <num of thread>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n_thr = atoi(argv[1]);

    pthread_t thr[n_thr];

    for (i=0; i<n_thr; i++) {
        
        if ((thr_err = pthread_create(&thr[i],NULL, thr_func, (void*)0)) != 0) {
            fprintf(stderr, "Err. pthread_create() %s\n", strerror(thr_err));
            exit(EXIT_FAILURE);
        }
    }

    for (i=0; i<n_thr; i++) {
        if ((thr_err = pthread_join(thr[i], NULL)) != 0) {
            fprintf(stderr, "Err. pthread_join() %s\n", strerror(thr_err));
            exit(EXIT_FAILURE);
        }
    }

    
    return(EXIT_SUCCESS);
}

void *thr_func(void *thr_num)
{
    pthread_t tid;
    global_var++;

    if ((tid = syscall(SYS_gettid)) == -1) { 
        fprintf(stderr, "Err. syscall() %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("thread - TID %lu - Address 0x%x - ", tid, (unsigned int)tid);

    printf("Variabile globale: %d\n", global_var);

    pthread_exit((void*)0);
}
