#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

static void signal_handler(int signum);

/* Lo scopo del programma e' di visualizzare un messaggio numerico progressivo
ogni qualvolta e' catturato il segnale SIGINT C^ */

int main(void) {

    if (signal(SIGINT, signal_handler) == SIG_ERR) {
    	fprintf(stderr, "Err.(%s), can't catch SIGINT\n", strerror(errno));
	    exit(EXIT_FAILURE);
    }

    /* La funzione pause() pone in attesa il processo in attesa di un segnale */
    while(1)
    	pause();

    return(EXIT_SUCCESS);
}

static void signal_handler(int signum) {
    static int count = 0;

    /* Ogni volta che il signal handler catturera' il segnale SIGINT, 
    sara' stampato in output un numero progressivo. Essendo la variabile
    count di tipo static sara' anche consecutivo. */
	if (signum == SIGINT) {
        count++;
        printf("Got SIGINT: %d\n", count);
        /* Ritorna al main() */
        return;
	}

	printf("Got SIGQUIT, bye bye.\n");

    exit(EXIT_SUCCESS);
}
