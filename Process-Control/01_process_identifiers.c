#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
A ciascun nuovo processo e' assegnato un intero di 16 bit non negativo e 
progressivo che lo identifica univocamente rispetto agli altri processi, il 
"Process ID" (PID); essendo peraltro un intero a 16 bit puo' raggiungere al 
massimo il valore di 32768, dopodiche' eventualmente, dopo la terminazione di un
processo puo' anche  essere riutilizzato, ma solo dopo uno specifico lasso di 
tempo.

PID 0, solitamente e' assegnato allo schedulatore dei processi, detto "swapper";
PID 1, e' assegnao ad "init", invocato dal kernel alla fine della procedura di 
"bootstrap", per cui e' il primo processo ad essere eseguito, e si occupa di 
far partire tutti gli altri processi. 

Il processo "init" non muore mai e sebbene venga eseguito con privilegi da 
"superuser" e' un normale processo utente e non un processo kernel.

Vi sono diverse funzioni che consentono l'identificazione dei processi:

HEADER    : <unistd.h>
PROTOTYPE : pid_t getpid(void);
            pid_t getppid(void);
	    uid_t getuid(void);
	    uid_t geteuid(void);
	    gid_g getgid(void);
	    gid_t getegid(void);
SEMANTICS : getpid() ritorna il PID del processo chiamante;
            getppid() ritorna il parent PID del processo chiamante;
	    getuid() ritorna il real user ID del processo chiamante;
	    geteuid() ritorna l'effective user ID del processo chiamante;
	    getgid() ritorna il real group ID del processo chiamante;
	    getegid() ritorno l'effective real group ID del processo chiamante.
RETURNS   : L'identificativo richiesto in caso di successo, nessun errore.
--------------------------------------------------------------------------------
Nota: Le due funzioni getpid() e getppid() servono per acquisire il PID del 
current process e il PID del parent process, ossia il PPID; da notare che il 
parent process del processo corrente risulta essere la shell in cui si esegue il 
programma.
*/

int main(int argc, char *argv[]) {
   printf("Processo chiamante:\n");
   printf("               PID: %d\n", getpid());
   printf("              PPID: %d - la shell\n", getppid());
   printf("      Real User ID: %d\n", getuid());
   printf(" Effective User ID: %d\n", geteuid());
   printf("     Real Group ID: %d\n", getgid());
   printf("Effective Group ID: %d\n", getegid());

   return(EXIT_SUCCESS);
}
/* L'effettiva valenza e utilita0 di ciascuna funzione sara' estremamente chiara
negli esempi successivi a questo, andando avanti nello studio dei processi */
