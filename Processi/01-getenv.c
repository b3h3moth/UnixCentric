#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * L'interazione tra processi e ambiente avviene mediante specifiche funzioni,
 * che non vanno confuse con le SystemCall, poiche' esse, le funzioni, non
 * interagiscono con il kernel.
 *
 * char *getenv(const char *name);
 * Verificando se 'name' corrisponde ad una variabile d'ambiente
 */

int main(int argc, char *argv[], char *envp[])
{
   
   char homedir[] = "HOME";
   char miadir[] = "/home/luka";


   if ( strcmp( getenv(homedir), miadir) != 0)
      fprintf(stderr, "Directory errata\n");
   else
   {
      printf("%s\n", getenv(homedir));
      printf("Operazione riuscita\n");
   }

   return(EXIT_SUCCESS);
}
