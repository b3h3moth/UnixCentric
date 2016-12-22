#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

/* Lo scopo del programma e' di convertire una variabile di tipo struct tm da
calendar-time a broken-down time, mediante la funzione mktime(). */

int main(void) {
    struct tm *ptm;
    time_t t, gm;

    if ((t = time(NULL)) < 0) {
       fprintf(stderr, "Err.(%s) getting time\n", strerror(errno));
       exit(EXIT_FAILURE);
    }

    ptm = localtime(&t);

    gm = mktime(ptm);
   
    printf("localtime() - ");
    printf("%d/%d/%d - %d:%d:%d\n",             \
            ptm->tm_mon = ptm->tm_mon + 1,      \
            ptm->tm_mday,                       \
            ptm->tm_year = ptm->tm_year + 1900, \
            ptm->tm_hour,                       \
            ptm->tm_min,                        \
            ptm->tm_sec);

    printf("localtime() to mktime() - %ld \n", gm);

    return(EXIT_SUCCESS);
}
