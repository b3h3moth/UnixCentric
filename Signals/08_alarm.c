#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define BELL "\007"

static void handler(int sig_num);

/*
La funzione alarm() setta un timer che allo scadere del tempo invia un segnale 
SIGALRM al processo; l'azione di default associata a SIGALRM è la terminazione.

HEADER    : <unistd.h>
PROTOTYPE : unsigned int alarm(unsigned int seconds);
SEMANTICS : La funzione alarm() invia un segnale SIGALRM dopo 'seconds' secondi
RETURNS   : 0 se non vi erano time-out impostati in precedenza oppure il numero
            di secondi mancante allo scadere del time-out precedente
--------------------------------------------------------------------------------
*/

/* Il programma riceve come parametro il numero di secondi dopo dei quali 
inviare un segnale al processo figlio mediante la funzione alarm(). */

int main(int argc, char *argv[]) {
    pid_t pid;
    int seconds;

    if (argc < 2) {
    	fprintf(stderr, "Uso: %s <seconds>\n", argv[0]);
	exit(EXIT_FAILURE);
    }
    
    /* La funzione atoi() non ritorna errori, per cui risulta inutile un
    eventuale controllo */
    seconds = atoi(argv[1]);

    if ((pid = fork()) < 0) {
    	fprintf(stderr, "Err.(%s) fork() failed\n", strerror(errno));
	exit(EXIT_FAILURE);
    } else if (pid == 0) {
	printf("Figlio, PID: %ld\n", (long)getpid());

	if (signal(SIGALRM, handler) == SIG_ERR) {
	    fprintf(stderr, "Err.(%s) sigalarm() failed\n", strerror(errno));
	    exit(EXIT_FAILURE);
	}

	/* Sara' inviato un segnale al processo dopo seconds secondi */
	alarm(seconds);

	pause();
    } else {
    	waitpid(-1,NULL,0);
	printf("Padre, PID: %ld\n", (long)getpid());
    }


    return(EXIT_SUCCESS);
} 

static void handler(int sig_num)
{
    printf("Segnale '%d' al PID: %ld\n", sig_num, (long)getpid());
    printf("%s",BELL);
}
