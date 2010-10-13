#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv, char **envp) {
   char *home_dir;

   /* Viusualizza l'esistenza della variabile d'ambiente HOME */
   if ( (home_dir = getenv("HOME")) != 0)
      printf("HOME DIRECTORY: %s\n", home_dir);

   /* Visualizza la presenza della varibile termo impostata
    * a vt220 e la modifica a vt100
    */

   char *term = 0;

   term = getenv("TERM");

   if ( term && !strcmp(term, "vt220"))
      putenv("TERM=vt100");

   /* Crea una nuova variabile d'ambiente TEST */

   char *new_var= "NOME";
   char *new_var_val = "Luca Suriano";

   setenv(new_var, new_var_val, 0); 	/* In questo caso il valore di overwrite no
   					   sarebbe necessario, in quanto la 
					   variabile deve essere creata da zero,
					   infatti il valore 0 corrisponde al true;
					   qualora avessi dovuto sovrascrirla,
					   avrei utilizzato 1, ovvero, false.
					   */
   printf("%s\n", getenv("NOME"));

   /* Rimuovo la variabile precedentemente creata */

   unsetenv(new_var);

   if ( (new_var = getenv("NOME")) == NULL) {
	fprintf(stderr, "%s\n", strerror(EIO));
   }

   return(EXIT_SUCCESS);
}
