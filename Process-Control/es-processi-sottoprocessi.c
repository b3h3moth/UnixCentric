/*
 * Programma che riceve da linea di comando un intero N e generi N
 * sottoprocessi, i quali durante il proprio avanzamento, stampano il loro PID e
 * quello del padre PPID. 
 * Il processo padre deve attendere che ciascun figlio termini e, man mano che
 * avviene la loro terminazione, registri i rispettivi PID in un array.
 * L'array infine viene stampato
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <wait.h>

int main(int argc, char *argv[])
{
   pid_t pid;
   int i, N, status, *db_pid;
   N = atoi(argv[1]);
   db_pid = malloc(N * sizeof(int));
   
   if (argc < 2) {
      fprintf(stderr,"Uso: %s [N] : %s\n", argv[0], strerror(errno));
      exit(EXIT_FAILURE);
   }


   printf("Il processo %ld genera %d sottoprocessi\n\n", (long)getpid(), N);

   for(i=0; i<N; i++) {
      pid = fork();
      
      if (pid < 0) {
      	 fprintf(stderr, "Err. fork() : %s\n", strerror(errno));
	 exit(EXIT_FAILURE);
      }

      if (pid == 0) {
      	 printf("In esecuzione il processo figlio :%ld - Il cui padre è %ld\n", 
	       (long)getpid(), (long)getppid());
	 break;
      } 
      
      if (pid > 0 ) {
      	 pid = wait(&status);
	 db_pid[i] = pid;
	 printf("In esecuzione il processo padre: %ld - Il cui padre e' %ld\n",
	       (long)getpid(), (long)getppid());
	 
	 printf("Processo figlio terminato: PID %d\n\n",  db_pid[i]);
      }
   }



   return(EXIT_SUCCESS);
}
