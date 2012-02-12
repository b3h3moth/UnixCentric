#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

/*
Calendar time: il numero di secondi a partire dalle 00:00 del 01 gennaio 1970
ITC, Epoch; indica il tempo su a cui l'orologio del kernel fa riferimento.

HEADER    : <time.h>
PROTOTYPE : time_t time(time_t *tm);
SEMANTICS : La funzione time() ritorna la data espressa in numero di secondi a 
            partire da Epoch, ossia 1970-01-01 00:00:00 +0000 (UTC), e salvata 
	    in 'tm'.
RETURNS   : Il valore di time in n caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
   time_t current_time;

   if (time(&current_time) < 0) {
      fprintf(stderr, "Err.(%s) getting time\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   printf("Dalle 00:00 del 01 gennaio 1970 sono trascorsi ");
   printf("%ld secondi\n", current_time);

   return(EXIT_SUCCESS);
}
