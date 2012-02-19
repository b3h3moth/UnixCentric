#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

/*
HEADER    : <sys/wait.h>
PROTOTYPE : pid_t wait(int status);
SEMANTICS : La funzione wait() sospende l'esecuzione del processo chimante fino
            a quando uno dei suoi figlo termina.
RETURNS   : Il Process ID del figlio terminato in caso di successo, -1 in caso 
            di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
   pid_t pid, wpid;
   int status;

   /* Si crea un processo figlio */
   pid = fork();

   switch(pid) {
      case -1:
      	 fprintf(stderr, "Err.(%s) fork() failed\n", strerror(errno));
	 exit(EXIT_FAILURE);

      case 0:
      	 printf("(PID %ld) Figlio in esecuzione, il Padre: %ld - pid=%ld\n",
	       (long)getpid(), (long)getppid(), (long)pid);
	 
	 printf("Figlio in attesa 5 secondi ....\n");
	 sleep(5);
	 printf("Figlio terminato ....\n");
	 exit(EXIT_SUCCESS);

      default:
      	 printf("(PID %ld) Padre  in esecuzione, il Padre: %ld - pid=%ld\n",
	       (long)getpid(), (long)getppid(), (long)pid);
	 

	 wpid = wait(&status);
	 
	 exit(EXIT_SUCCESS);
   }


   return(EXIT_SUCCESS);
}

/*
[1] Files-and-Directories: 13_duplicate_file_descriptor.c
*/
