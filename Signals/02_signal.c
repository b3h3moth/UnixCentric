#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

/*
L'interfaccia piu' semplice relativa alla gestione dei segnali nei sistemi unix-
like e' la funzione signal(); tale funzione e' standard ISO C, il quale pero'
non  considera ne' il multitasking, ne' il process group, ne' il terminal I/O e 
cosi' via, pertanto la funzione signal() e' diventata nel tempo inutile nei
sistemi unix-like, e poiche' la semantica differisce totalmente da un sistema
all'altro si consiglia di adoperare la funzione sigaction().

La funzione signal() e' tratatta per puro scopo didattico.

HEADER    : <signal.h>
PROTOTYPE : typedef void (*sighandler_t)(int);
            sighandler_t signal(int signum, sighandler_t handler); 
SEMANTICS : La funzione signal() associa o installa la funzione di gestione 
            'handler' al segnale 'signum'
RETURNS   : Il gestore precedente in caso di successo, SIG_ERR in caso di errore
--------------------------------------------------------------------------------
Nota: si e' utilizzata la typedef per rendere il prototipo della funzione
      meno ostico da leggere ed interpretare, il tipo di dato sighandler_t e'
      una estensione GNU delle glibc. Il prototipo della funzione pertanto e'
      caratterizzato da due argomenti, l'intero 'signum' e un puntatore ad una
      funzione void che riceve come argomento un intero. Il secondo argomento
      della funzione signal() e' definito "signal handler" - gestore del 
      segnale.

'signum' e' il nome del segnale, mentre il valore della funzione handler puo' 
essere: 
- l'indirizzo della funzione da chiamare al verificarsi del segnale;
- la costante SIG_IGN, per ignorare il segnale;
- la costante SIG_DFL, per l'azione di default del segnale.

Se si specifica l'indirizzo della funzione si sta parlando di "signal handler" o
di "signal-catching function" - gestore del segnale o funzione per la cattura 
di un segnale.

La funzione restituisce l'indirizzo dell'azione precedente, che puo' essere
salvato per poi essere riutilizzato in un secondo tempo.

*/

static void sig_usr(int);

int main(int argc, char *argv[]) {
    
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
    	fprintf(stderr, "Err.(%s), cant' catch SIGUSR1\n", strerror(errno));
	exit(EXIT_FAILURE);
    }

    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
    	fprintf(stderr, "Err.(%s), cant' catch SIGUSR2\n", strerror(errno));
	exit(EXIT_FAILURE);
    }

    for(;;)
    	pause();

    return(EXIT_SUCCESS);
}

static void sig_usr(int signo)
{
    if (signo == SIGUSR1)
    	printf("Ricevuto il segnale: SIGUSR1\n");
    else {
    	abort();
	exit(EXIT_FAILURE);
    }
}
