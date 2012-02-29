#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
HEADER    : <unistd.h>
PROTOTYPE : int execl(const char *path, const char *arg, ...);
SEMANTICS : La funzione execl() esegue il programma 'path', a tale programma
            puo' essere passara la lista di argomenti arg0 ... argN.
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
Nota: La desinenza 'l' nel nome della funzione indica che il programma puo' 
ricevere una lista di argomenti nella forma arg0, arg1, ... argN; l'eseguibile
va cercato nel PATH indicato da 'path'.
*/

/* Il programma stampa in output la lista dei file della directory corrente
utilizzando la funzione execl() nel processo figlio */

int main(int argc, char *argv[]) {
    pid_t pid;

    switch (pid = fork()) {
    	case -1:
	    fprintf(stderr, "Err.(%s) fork() failed\n", strerror(errno));
	    exit(EXIT_FAILURE);

	case 0:
	    if (execl("/bin/ls", "ls","-l",(char *)0) < 0) {
	    	fprintf(stderr, "Err.(%s) execl() failed\n", strerror(errno));
		exit(EXIT_FAILURE);
	    }

	default:
	    waitpid(pid, NULL, 0);
	    printf("padre: Lista del figlio completata\n");
    }

   return(EXIT_SUCCESS);
}
