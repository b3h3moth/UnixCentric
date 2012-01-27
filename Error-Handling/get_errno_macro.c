#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
 Questo semplicissimo programmino serve per verificare il tipo di errore 
 associato alla variabile errno; e' sufficiente fornire il numero in input
 per avere le informazioni su quella specifica macro.
*/

int main(int argc, char *argv[]) {

   if (argc < 2) 
      fprintf(stderr, "Uso: %s <errno_number>\n", argv[0]);
   else {
      errno = atoi(argv[1]);
      perror(argv[1]);
      /* 
       stesso risultato con:
       perror(""); 
      */
   }
   
   return(EXIT_SUCCESS);
}
