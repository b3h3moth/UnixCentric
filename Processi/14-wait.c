#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
   pid_t pid;
   int status; /* nel caso specifico mi riferisco al 
   		 termination status del processo figlio*/
   pid = fork();

   if (pid == 0)
   {
      printf("Esegue il processo figlio...\n");
      sleep(2);
      status = execl("/usr/bin/vim","vim","tabelle.txt",NULL);

      if (status == -1)
      	 printf("Errore in execl");
      exit(1);
   }
   
   wait(&status);

   printf("Esegue il padre...\n");
   sleep(2);

   return(EXIT_SUCCESS);
}
