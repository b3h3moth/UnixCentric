#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* Lo scopo del programma e' di stampare in output nella forma 'Calendar time'
il tempo trascorso tra la prima e la seconda chiamata a time(); sara'
utilizzata la funzione difftime() per calcolare tale tempo */

int main(void) {
   time_t start, end;

   if ((start = time(&start)) < 0) {
      fprintf(stderr, "Err.(%s) getting time(), start\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   /* Si sospende l'esecuzione per 5 secondi */
   sleep(5);

   if ((end = time(&end)) < 0) {
      fprintf(stderr, "Err.(%s) getting time(), end\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   /* Stampa a video della sospensione mediante la funzione difftime() */
   printf("Tempo trascorso: %.f secondi\n", difftime(start, end));

   return(EXIT_SUCCESS);
}
