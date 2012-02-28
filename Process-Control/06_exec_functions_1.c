#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
I processi in unix sono utilizzati per diversi motivi, uno dei principali e' di
utilizzarli per lanciare nuovi programmi, tale caratteristica e' propria della
famiglia delle funzioni exec.

Allorquando un processo viene chiamato da una delle funzioni exec, tale processo
e' completamente rimpiazzato da un nuovo programma - in pratica l'immagine del
processo corrente viene rimpiazzata da una nuova immagine - , il quale inizia la
l'esecuzione dalla funzione main() - come qualsiasi altro programma del resto -,
il PID non cambia poiche' non e' stato creato un nuovo processo, ma si "limita"
a rimpiazzare testo, dati, heap e il segmento dello stack.

La famiglia delle funzioni exec comprende sei differenti funzioni, tuttavia 
solo la funzione execve() e' una system call vera e propria, le altre cinque
sono semplicemente funzioni di libreria che si appoggiano ad essa.

HEADER    : <unistd.h>
PROTOTYPE :
 int execl(const char *path, const char *arg0, ... );
 int execv(const char *path, char *const argv[]);
int execle(const char *path, const char *arg0, ... , char *const envp[]);
int execve(const char *path, char *const argv[], char *const envp[]);
int execlp(const char *file, const char *arg0, ...);
int execvp(const char *file, char *const argv[]);
SEMANTICS : Eseguono il programma definito in 'path' on in 'file', con o senza
            argomenti.
RETURNS   : Ritornano solo in caso di errore, restituendo -1
--------------------------------------------------------------------------------
Nota: I prototipi delle funzioni, seppur piuttosto complessi da ricordare, hanno
il vantaggio che possono essere facilmente memorizzati grazie a specifiche
lettere che compongono ciascuna funzione:

- p = La funzione utilizza come argomento un filename per cercare in PATH il
      file eseguibile;
- l = La funzione utilizza una lista di argomenti;
- v = La funzione utilizza il vettore argv[];
- e = La funzione utilizza l'array envp[] per interagire con l'ambiente.

Differenze tra le varie funzioni:
1 - La modalita' di esecuzione del programma. 
    Le prime quattro funzioni eseguiranno il programma definito da un 'path', 
    le ultime due funzioni invece eseguiranno il programma specificato mediante
    un 'file', lettera p.

2 - Il passaggio dei parametri.
    Si considerano le lettere all'interno della funzione v ed l, la prima e' un
    vettore la seconda una lista; nel primo caso gli argomenti sono passati 
    mediante il vettore di puntatori ad argv[], seguite da un puntatore nullo, 
    nel secondo caso gli argomenti sono passati come una lista di puntatori, 
    terminata da un puntatore nullo.

3 - Il passaggio della lista delle variabili d'ambiente.
    Le funzioni con la lettera e utilizzeranno l'array envp[] per interagire
    con l'ambiente, le altre utilizzeranno la variabile globale esterna environ.
*/

char *env_int[] = { "USER=unknow", "PATH=/tmp", NULL};

int main(int argc, char *argv[]) {
    pid_t pid;

    if ((pid = fork()) < 0) {
    	fprintf(stderr, "Err.(%s) fork() failed\n", strerror(errno));
	exit(EXIT_FAILURE);
    } else if (pid == 0) { /* Si specifica il path e l'ambiente */
    	if (execle("/home/b3h3m0th/devel/L-LP/Process-Environment/a.out",
		    "a.out", "myarg1", "MYARG2", (char *)0, env_int) < 0) {
	    fprintf(stderr, "Err.(%s) execle() failed\n", strerror(errno));
	    exit(EXIT_FAILURE);
	}
    }

	if (waitpid(pid, NULL, 0) < 0) {
	    fprintf(stderr, "Err.(%s) waitpid() failed\n", strerror(errno));
	    exit(EXIT_FAILURE);
	}

	if ((pid = fork()) < 0) {
	    fprintf(stderr, "Err.(%s) fork() 2 failed()\n", strerror(errno));
	    exit(EXIT_FAILURE);
	} else if (pid == 0) {
	    if (execlp("a.out", "a.out", "only 1 arg", (char*)0) < 0) {
	    	fprintf(stderr, "Err.(%s) exelp() failed\n", strerror(errno));
		exit(EXIT_FAILURE);
	    }
	}


    
    return(EXIT_SUCCESS);
}
