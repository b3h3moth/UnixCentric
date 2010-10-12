#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 

int main(int argc, char *argv[], char *envp[])
{
   char *parametri[] = {"search", "mutt", NULL};

   printf("Esempio con execvp()");

   execvp("aptitude", parametri);

   return(EXIT_SUCCESS);
}
