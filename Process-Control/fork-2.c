#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int glob_var = 10;
char buf[] = "UNIX Programming\n";

int main(int argc, char *argv[], char *envp[])
{
   int var;
   pid_t pid;
   var = 100;

   if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
      fprintf(stderr, "%d: %s err.\n", errno, strerror(errno));

   printf("Prima della chiamata fork()\n");

   if ((pid = fork()) < 0)
      fprintf(stderr, "%d: %s err.\n", errno, strerror(errno));
   else if ( pid == 0)
   {
      /* Child Process */
      glob_var++;
      var++;
   }
   else
      /* Parent Process */
      sleep(2);

   /* 
    Da notare che in realta' non si sa se Child Process sara' eseguito prima del
    Parent Process o viceversa, l'esecuzione di ciascun processo infatti e' 
    gestita dall'algoritmo di scheduling implementato nel kernel.
   */

   printf("pid = %d, glob_var = %d, var = %d\n", getpid(), glob_var, var);

   return(EXIT_SUCCESS);
}
