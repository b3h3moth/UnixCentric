#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 

int main(int argc, char *argv[], char *envp[])
{
   int i;
   puts("sono nel programma");
   
   i = system("echo ora sono nella shell");
   sleep(3);
   puts("di nuovo nel programma");

   return(EXIT_SUCCESS);
}
