#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Lo scopo del programma e' di stampare in output nella forma 'Calendar time'
la data corrente e i secondi trascorsi da Epoch. */

int main(void) {
   time_t cur;

   /* Se si utilizza NULL come argomento della funzione non e' necessario
   verificare gli errori */
   cur = time(NULL);

   printf("Seconds since the Epoch: %d\n", (unsigned int)cur);
   printf("%s\n", asctime(localtime(&cur)));

   return(EXIT_SUCCESS);
}
