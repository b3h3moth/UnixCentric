#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int glob = 6;
char buf[] = "a write to stdout\n";

int main(int argc, char *argv[], char *envp[])
{
   int var;
   pid_t pid;
   var = 88;

   if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
      printf("err...sys\n");

   printf("before fork\n");

   if ( (pid == fork()) < 0)
      printf("err...\n");
   else if ( pid == 0)
   {
      glob++;
      var++;
   }
   else
      sleep(2);

   printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);


   return(EXIT_SUCCESS);
}
