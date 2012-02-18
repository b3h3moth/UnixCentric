#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Lo terminazione dei processi insegna[1] che se alla sua 'nascita' ogni nuovo
processo ha sempre un padre, non e' detto che questo sia vero anche alla 
conclusione del processo stesso; cosa succederebbe se morisse il padre lasciando
il figlio in piena salute? Il figlio sarebbe un orfano, ma non per molto,
poiche' init() lo accoglierebbe immediatamente a braccia aperte.

Sebbene romanzato, e' proprio cio' che succederebbe, ossia se il processo padre 
dovesse terminare con il processo figlio ancora in esecuzione, il figlio sarebbe
per un lasso di tempo un processo orfano, dopodiche' init() diventerebbe il
nuovo processo genitore; tecnicamente si direbbe che il processo figlio e' stato
ereditato da init().

Nota: Il kernel, quando un processo termina, provvede a verificare se tale 
processo e' il padre di altri processi in esecuzione, in caso di esito positivo
il PPID (Parent PID) di questi specifici processi viene posto al PID di init(),
ovvero 1; in tal modo ciascun processo avra' sempre un padre a cui riporftare il
proprio stato di terminazione.
*/

void child_process(void);
void parent_process(pid_t pid);

int main(int argc, char *argv[]) {
/* Programma che genera un processo figlio e che poi termina prima del figlio
stesso, rendendolo orfano; attenzione, non si sta parlando di zombie, lo scopo 
e' di far adottare l'orfano da init
*/
   pid_t pid;

   printf("PID = %ld - Parent PID = %ld\n", (long)getpid(), (long)getppid() );

   pid = fork(); 

   if (pid == -1) {
      perror("fork");
      exit(13);
   }

   if (pid == 0)
      child_process();
   else
      parent_process(pid);

   return(EXIT_SUCCESS);
}

void child_process(void)
{
   sleep(10);
   printf("Child Process\n");

   if (getppid() == 1)
      printf("Ho perso il padre\n");

   printf("PID = %ld - Parent PID = %ld\n", (long)getpid(), (long)getppid());
}

void parent_process(pid_t pid)
{
   printf("Parent Process\n");
   printf("PID = %ld - PID %ld - Parent PID = %ld\n", 
   	 (long)pid, (long)getpid(), (long)getppid());

}
/*
[1] ../Process-Environment/01_process_termination.c
*/
