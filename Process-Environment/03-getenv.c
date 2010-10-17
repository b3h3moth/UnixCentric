#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv, char **envp) {
   char *home_dir;

   /* Verifica la presenza della variabile d'ambiente HOME */
   if ( (home_dir = getenv("HOME")) != 0)
      printf("HOME DIRECTORY: %s\n", home_dir);

   /* Visualizza la presenza della varibile term impostata
    * a vt220 e la modifica a vt100*/
   char *term = getenv("TERM");

   if ( term && !strcmp(term, "vt220"))
      putenv("TERM=vt100");

   /* Crea una nuova variabile d'ambiente TEST */
   char *new_var= "TEST";
   char *new_var_val = "Linux Programming";

   /* In questo caso il valore di overwrite non sarebbe necessario, in quanto
	* la variabile deve essere creata da zero, infatti il valore 0 corrisponde
	* al true; qualora avessi dovuto sovrascriverla, avrei utilizzato 1, ovvero,
	* false. */
   setenv(new_var, new_var_val, 0); 	

   printf("Nuova variabile di ambiente TEST: %s\n", getenv("TEST"));

   /* Rimuovo la variabile precedentemente creata, in seguito pertanto ci sara'
	* un errore */
   unsetenv(new_var);

   if ( (new_var = getenv("TEST")) == NULL) {
   	   fprintf(stderr, "Variabile di ambiente: %s\n", strerror(EIO));
   }

   return(EXIT_SUCCESS);
}
