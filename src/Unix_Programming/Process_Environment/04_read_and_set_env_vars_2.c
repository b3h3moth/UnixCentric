#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

extern char **environ;

/* Lo scopo del programma e' di azzerare l'aambiente mediante clearerr(), 
dopodiche' aggiungere due nuove 'environment variables', la prima ottenuta 
dalla command-line e settata con putenv() la seconda impostata nel programma 
stesso con setenv(). 

Compilare mediante la macro -D_GNU_SOURCE
*/

int main (int argc, char *argv[]) {
   int i;
   char **var;
  
   /* Si intende aggiungere una variabile d'ambiente come argomento */
   if (argc < 4) {
      fprintf(stderr, "Uso: %s name=value\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   /* Cancella l'intero ambiente */
   clearenv();

   /* La variabile d'ambiente acquisita come argomento viene aggiunta alla
   environment list; ora vuota */
   for (i = 1; i < argc; i++)
      if (putenv (argv[i]) != 0) {
      	 fprintf (stderr, "Err.(%s) - put env\n", strerror(errno));
	    exit(EXIT_FAILURE);
   }
   
   /* Si aggiunge una ulteriore variabile d'ambiente con setenv() */
   if (setenv ("E-MAIL", "b3h3m0th@mail.org", 0) < 0) {
      fprintf (stderr, "Err.(%s) - set env\n", strerror(errno));
      exit(EXIT_FAILURE);
   }
   
   /* Poiche' l'intero ambiente e' stato cancellato da clearenv(), l'ouput
   sara' molto breve; l'environment list infatti comprendera' solo le due
   variabili d'ambiente aggiunte nell'ambito del processo in esecuzione */
   for (var = environ; *var != NULL; var++)
      printf("%s\n", *var);
   
   exit (EXIT_SUCCESS);
}
