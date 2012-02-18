#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
La funzione vfork() e' deprecata, si consiglia di utilizzare sempre la fork();
la semantica e' esattamente la stessa della fork(), la differenza sostanziale e'
che la vfork() non crea ne' la "page table" ne' la "task struct" per il nuovo
processo. Il processo padre e' posto in attesa che il figlio termini la propria
esecuzione eseguendo una funzione della famiglia execve() o _exit().

HEADER    : <unistd.h>
PROTOTYPE : pid_t vfork(void);
SEMANTICS : La funzione vfork() crea un processo figlio del processo chiamante
RETURNS   : Il PID del processo figlio e 0 in caso di successo, -1 in caso di 
            errore
--------------------------------------------------------------------------------
*/


int glob = 10;

int main(int argc, char *argv[], char *envp[]) {
   int var;
   pid_t pid;

   var = 100;

   printf("Prima della fork()\n");

   if ((pid = vfork()) < 0)
      fprintf(stderr, "Err.(%d) - vfork - %s\n", errno, strerror(errno));
   else if  (pid == 0) {
      /* Child Process */
      glob++;
      var++;
      _exit(0); 
   }
   
   /* Parent Process */

   printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);

   return(EXIT_SUCCESS);
}
