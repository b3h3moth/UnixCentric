#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

/* Lo scopo del programma e' di convertire una variabile di tipo struct tm da
calendar-time a broken-down time, mediante la funzione mktime(). */

int main(void) {
    struct tm *ptm;
    time_t t, new_time;

    if ((t = time(NULL)) < 0) {
       fprintf(stderr, "Err.(%s) getting time\n", strerror(errno));
       exit(EXIT_FAILURE);
    }

    ptm = localtime(&t);

    new_time = mktime(ptm);
   
    printf("%ld since The Epoch\n", new_time);

    return(EXIT_SUCCESS);
}
