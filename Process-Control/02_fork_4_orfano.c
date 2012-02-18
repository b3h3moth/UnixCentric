#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Programma che genera un processo figlio e che poi termina prima del figlio
stesso, rendendolo orfano; attenzione, non si sta parlando di zombie, lo scopo 
e' di far adottare l'orfano da init
*/

void child_process(void);
void parent_process(pid_t pid);

int main(int argc, char *argv[]) {
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
