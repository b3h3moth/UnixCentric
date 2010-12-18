#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* fork() */
#include <sys/wait.h> /* wait() */
#include <sys/types.h> /* atoi() */


int main(int argc, char *argv[], char *envp[])
{
   pid_t pid;
   int n1 = 0;
   int n2 = 0;

   if (argc < 2)
   {
      printf("Errore\n"), exit(-1);
   }

   n1 = atoi(argv[1]);
   n2 = atoi(argv[2]);

   pid = fork();

   if (pid == 0)
   {
      printf("Il figlio la somma %d + %d = %d\n", 
      	    n1, n2, n1+n2);
      exit(0);
   }
   else if (pid > 0)
   {
      printf("Il padre la moltiplicazione %d * %d = %d\n", 
      	    n1, n2, n1*n2);
      exit(0);
   }

   printf("Non ci arriva mai\n");

   return(EXIT_SUCCESS);
}
