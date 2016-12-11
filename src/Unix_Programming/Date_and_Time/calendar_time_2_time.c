#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* Lo scopo del programma e' di stampare in output nella forma 'Calendar time'
la data corrente e i secondi trascorsi da Epoch. */

int main(void) {
   time_t cur;

   /* Se si utilizza NULL come argomento della funzione non e' necessario
   verificare gli errori */
   cur = time(NULL);

   /* Si sospende l'esecuzione per 3 secondi */
   sleep(3);

   printf("Tempo trascorso: %ju secondi\n", cur);

   return(EXIT_SUCCESS);
}
