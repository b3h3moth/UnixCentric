#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
HEADER    : <stdlib.h>
PROTOTYPE : int system(const char *cmdstring);
SEMANTICS : La funzione esegue il comando definito in 'cmdstring'.
RETURNS   : Poiche' system() e' implementata utilizzando fork(), exec e 
            waitpid(), puo' avere 3 tipi di valori di ritorno:
	    1 - Se la fork() fallisce o la waitpid() ritorna un errore diverso
	        da EINTR, restituira' -1;
            2 - Se la exec fallisce impedendo cosi' l'esecuzione di /bin/sh 
	        restitura' exit(127);
            3 - Se non ci sono errori, restituira' il termination status della
	        shell, nella forma specificata per waitpid().
--------------------------------------------------------------------------------
La funzione esegue un comando specificato in 'cmdstring' nella forma:
/bin/sh -c 'cmdstring', e ritorna solo dopo che il comando sara' completamente
portato a termine.

La funzione system() e' standard ISO C, tuttavia il suo comportamento e'
fortemente dipendente dal sistema; durante l'esecuzione del comando 'cmdstring'
il segnale SIGCHLD sara' bloccato, mentre i segnali SIGINT e SIGQUIT saranno
ignorati. */

/* Si provvede ora alla implementazione di un clone della funzione system(),
la differenza sostanziale e' che non c'e' la gestione dei segnali, tuttavia
anche in questo modo e' estremamenge utile per capire come lavora la funzione in
oggetto. */
int system_clone(const char *cmd_string);

int main(int argc, char *argv[]) {
    system_clone("ps U b3h3m0th");
    system_clone(NULL);
    system_clone("fottiti");

    return(EXIT_SUCCESS);
}

int system_clone(const char *cmd_string)
{
    pid_t pid;
    int status;

    if (cmd_string == NULL)
    	return(1);

    if ((pid = fork()) < 0) {
    	status = -1;
    } else if (pid == 0) {
    	execl("/bin/sh", "sh", "-c", cmd_string, (char *)0);
	_exit(127);
    } else {
    	while (waitpid(pid, &status, 0) < 0) {
	    if (errno != EINTR) {
	    	status = -1;
		break;
	    }
	}
    }

    return(status);
}
