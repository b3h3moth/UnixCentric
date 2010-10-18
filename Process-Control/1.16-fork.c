
/*
 * Scrivere un programma che crei un sottoprocesso e che consenta di verificare
 * la porzione del processo padre e del processo figlio
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
   pid_t pid;

   pid = fork();

   if (pid == 0)
      printf("Processo figlio %ld\n", (long)getpid() );
   else
      printf("Processo padre %ld\n", (long)getpid() );

   return(EXIT_SUCCESS);
}
