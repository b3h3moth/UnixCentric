#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 

int main(int argc, char *argv[], char *envp[])
{
   printf("PID processo corrente %d\n", getpid());
   printf("PID processo padre %d\n", getppid());

   return(EXIT_SUCCESS);
}
