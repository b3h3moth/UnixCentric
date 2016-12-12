#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

/* Lo scopo del programma e' di convertire un tipo time_t in una stringa
mediante l'utilizzo della funzione ctime() */

int main(void) {
    time_t t;	
    char *str_time;	
   
    if (time(&t) < 0) {
       fprintf(stderr, "Err.(%s) getting time()\n", strerror(errno));
       exit(EXIT_FAILURE);
    }

    /* La conversione in stringa, partendo da un valore di tipo time_t */
    if ((str_time = ctime(&t)) == NULL) {
       fprintf(stderr, "Err.(%s) str conversion: ctime()\n", strerror(errno));
       exit(EXIT_FAILURE);
    }

    printf("%s", str_time);
    
    return(EXIT_SUCCESS);
}
