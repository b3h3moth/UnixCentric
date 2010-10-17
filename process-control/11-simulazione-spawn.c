#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int spawn(char *prog, char *arg_list[]);

int main(int argc, char *argv[], char *envp[])
{
   char *args[] = {"ls", "-l", NULL};
   char *programma = "ls";

   spawn(programma, args);

   return(EXIT_SUCCESS);
}

int spawn(char *prog, char *arg_list[])
{
   pid_t child_pid;
   child_pid = fork();

   if (child_pid != 0)
      return child_pid;
   else
   {
      if (execvp(prog, arg_list) == -1)
      	 printf("Err.\n");
      exit(EXIT_FAILURE);
   }
}
