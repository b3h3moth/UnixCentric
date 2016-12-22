#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

/* Lo scopo del programma e' di convertire una variabile di tipo time_t
in una stringa di tipo broken-down time, espressa mediante ora legale */

int main(void) {
    time_t t;
    struct tm *local_time;
  
    if ((t = time(NULL)) < 0) {
       fprintf(stderr,"Err.(%s) getting time\n", strerror(errno));
       exit(EXIT_FAILURE);
    }
   
    local_time = localtime(&t);
   
    printf("%d/%d/%d - %d:%d:%d\n", \
            local_time->tm_mon,     \
            local_time->tm_mday,    \
            local_time->tm_year,    \
            local_time->tm_hour,    \
            local_time->tm_min,     \
            local_time->tm_sec);

    return(EXIT_SUCCESS);
}
