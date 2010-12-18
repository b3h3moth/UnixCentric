#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
   pid_t pid;
   pid = fork();

   if (pid > 0)
      sleep(60);
   else
      exit(0);

   return(EXIT_SUCCESS);
}
