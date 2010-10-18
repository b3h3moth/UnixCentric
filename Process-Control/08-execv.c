#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main(int argc, char *argv[], char *envp[])
{
   printf("Esempio con execv()");
   char *parametri[] = {"ps -aux", NULL};
   execv("/bin/ps", parametri);

   return(EXIT_SUCCESS);
}
