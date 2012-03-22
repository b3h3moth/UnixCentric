#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

/*
Quando un processo termina o si ferma, il segnale SIGCHLD e' inviato al processo
padre, da notare tuttavia che il comportamento di default consiste nell'ignorare
il segnale, per cui il processo padre deve catturare il segnale se vuole essere
notificato sul cambiamento di stato del processo figlio.

Il comportamento solito del signal handler prevede l'invocazione di una delle 
funzioni della famiglia wait() affinche' si possa acquisire lo stato e il PID 
del processo figlio.

Nota storica: Le prime versioni di UNIX System V comprendevano il segnale SIGCLD
              con una semantica del tutto differente a SIGCHLD, il suo utilizzo
	      non e' consigliato. Linux, BSD e POSIX non lo supportano e 
	      oltretutto il segnale SIGCLD talvolta e' indicato come un sinonimo
	      di SIGCHLD stesso. 

Semantica
---------
Quando occorre un segnale SIGCHLD, lo stato del processo figlio cambia, vi e'
pertanto la necessita' di invocare una delle funzioni wait() affinche' si possa
determinare l'accaduto.


HEADER    : 
PROTOTYPE : 
SEMANTICS : 
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

#define MAX_PR 2

static void signal_handler(int sig_num);

int main(int argc, char *argv[]) {
    pid_t pid;
    int i;
    signal(SIGCHLD, signal_handler);

    for (i=0; i<MAX_PR; i++) {
    	if ((pid = fork()) < 0) {
	    fprintf(stderr, "Err.(%s) fork() failed\n", strerror(errno));
	    exit(EXIT_FAILURE);
	} else if (pid == 0) {
	    sleep(1);
	    exit(0);
	}
    }

    while(1)
    	;

    return(EXIT_SUCCESS);
}

static void signal_handler(int sig_num)
{
    pid_t pid;
    int child_status;
    pid = waitpid(-1, &child_status, 0);
    printf("Ricevuto segnale %d dal processo %ld\n", sig_num, (long)pid);
}
