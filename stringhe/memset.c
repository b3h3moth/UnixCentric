#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 
#include <string.h>

void stampa( char *s)
{
   printf("output: %s\n", s);
}

int main(int argc, char *argv[], char *envp[])
{
   char stringa[] = "UNIX Programming with POSIX";
   /* La memset puo' essere utilizzata, ad esempio, per azzerare un array, 
	* tuttavia c'e' una sottile considerazione da porre in essere: se
    * utilizzo uno zero - numero - , la stringa sara' effettivamente 
	* azzerata, ma se altrimenti utilizzo il carattere 0 l'array sara' 
	* rimpito di tanti zeri. */
   int n_zero = 0;
   char c_zero = '0';
   int size = strlen(stringa);

   /* Azzero l'array */
   memset(stringa, c_zero, size);
   stampa(stringa);

   /* Inserisco per ogni byte uno zero */
   memset(stringa, n_zero, size);
   stampa(stringa);

   return(EXIT_SUCCESS);
}
