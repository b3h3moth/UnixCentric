#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
   int retcode;

   if (retcode != 0)
      printf("Processo padre ID %d - parent ID %d\n", getpid(), getppid());
   else
      printf("Processo figlio ID %d - retcode%d\n", retcode, getppid());

   printf("stampa questa linea %d\n", getpid());

   sleep(10);
   return(EXIT_SUCCESS);
}
