#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Si consiglia di leggere il sorgente in cui si introduce il controllo di
accesso[1] prima di proseguire con le funzioni per la modifica dell'identita'.

HEADER    : <unistd.h>
PROTOTYPE : int setuid(uid_t uid);
SEMANTICS : La funzione setta il real user-ID e l'effective user-ID
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
Quando un programma necessita di privilegi addizionali oppure ottenere l'accesso
a specifiche risorse per le quali non si hanno i dovuti privilegi, si devono 
modificare l'user-ID (UID) e il group-ID (GID); naturalmente questa e' la strada
da seguire anche qualora i privilegi dovessero essere ridotti.

Attenzione; si assume che la costante _POSIX_SAVED_IDS sia settata, altrimenti
i riferimenti a saved UID non saranno disponibili, per verificarlo e' possibile
invocare la funzione sysconf() con l'argomento _SC_SAVED_IDS a run-time oppure a
compile-time con _POSIX_SAVED_IDS.

Le applicazioni dovrebbero essere sviluppate seguendo il modello del 
"least privilege", ossia il principio del privilegio minimo; in informatica e 
in altri campi, il principio del privilegio minimo richiede che in un 
particolare livello di astrazione di un ambiente di calcolo ogni modulo 
computazionale (un processo, un programma o un utente a seconda del livello di 
astrazione considerato) abbia visibilità delle sole risorse necessarie al suo 
funzionamento. Lo scopo dell'applicazione del principio e' quello di concedere 
solo il minimo insieme di privilegi possibile in ogni istante, in modo da 
migliorare la protezione del sistema.

La funzione setuid() consente di modificare il real-UID e l'effective-UID, vi
sono regole ben precise a riguardo:

1 Se il processo gode dei privilegi di super-user, la funzione setuid() setta
  il real UID, l'effective UID e il saved UID a 'uid';[1]

2 Se il processo non gode dei privilegi di super-user, e 'uid' e' uguale o al
  real-UID o al saved-UID, la funzione setuid() imposta solo l'effective-UID
  a 'uid';
  
3 Se nessuna delle condizioni sopra citate e' vera, 'errno' e' impostata
  a EPERM, e la funzione setuid() ritorna -1.
*/


int main(int argc, char *argv[]) {
    pid_t pid;
    char *log_kernel = "/var/log/kern.log";
    char *prog_args[] = {"./clone_cat", log_kernel, (char *)0};

    switch(pid = fork()) {
    	case -1:
	    fprintf(stderr, "Err.(%s) fork() failed\n", strerror(errno));
	    exit(EXIT_FAILURE);

	case 0:
	    
	    if (execv("./clone_cat", prog_args) < 0) {
	    	fprintf(stderr, "Err.(%s) execv() failed\n", strerror(errno));
		exit(EXIT_FAILURE);
	    }
	    
	default:
	    waitpid(pid, NULL, 0);
    }

    return(EXIT_SUCCESS);
}
/*
[1] ../Process-Control/01_process_identifiers.c
*/
