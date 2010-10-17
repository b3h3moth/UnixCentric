#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 

int main(int argc, char *argv[], char *envp[])
{
   printf("Esempio con execlp()");

   execlp("ls","-l", NULL);

   return(EXIT_SUCCESS);
}
