#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 

/*
 * Un processo lavoro all'interno di un sistema operativo, o meglio, gira
 * all'interno di esso, ovvero in un ambiente specifico; nei sistemi UNIX vi
 * sono diverse variabili d'ambiente utili per gli scopi piu' disparati.
 *
 * Le varaiabili d'ambiente sono caratterizzate dal seguente formato:
 * name = value
 * HOME = user
 *
 * L'indirizzo della lista delle variabili di ambiente e' passato attraverso la
 * variabilr globale 'environ'.
 */

extern char **environ;

int main(int argc, char *argv[], char *envp[])
{
   char **var = environ;

   for( ; *var != NULL; var++)
      printf("%s\n", *var);

   return(EXIT_SUCCESS);
}
