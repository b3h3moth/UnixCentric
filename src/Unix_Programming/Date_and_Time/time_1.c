#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* Lo sco

int main(void) {
   time_t start, end;

   if ((start = time(&start)) < 0) {
      fprintf(stderr, "Err.(%s) getting time(), start\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   /* Sospendo l'esecuzione del programma per circa 1 secondo e mezzo, espresso
    in millisecondi */
   sleep(5);

   if ((end = time(&end)) < 0) {
      fprintf(stderr, "Err.(%s) getting time(), end\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   /* Come si potra' notare non sara' preciso il risultato */
   printf("Tempo trascorso: %f secondi\n", difftime(start, end));

   return(EXIT_SUCCESS);
}
