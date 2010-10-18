#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


int main(int argc, char *argv[])
{
   alarm(3); /* invia SIGALRM dopo 3 secondi */
   printf("Eseguo...\n");
   while(1);
   printf("non mi vedrai mai...");

   return(EXIT_SUCCESS);
}
