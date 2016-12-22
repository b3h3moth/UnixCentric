#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

/* Lo scopo del programma e' di convertire una data da time_t a Broken-down
time UTC mediante la funzione gmtime(). */

int main(void) {
    time_t t;
    struct tm *local_gm;
    
    if ((t = time(NULL)) < 0) {
        fprintf(stderr,"Err.(%s) getting time\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    local_gm = gmtime(&t);
    
    printf("  year: %d\n  month: %d\nday: %d\n   time: %d:%d:%d\n", \
            local_gm->tm_year, local_gm->tm_mon, local_gm->tm_mday, \
            local_gm->tm_hour, local_gm->tm_min, local_gm->tm_sec);
    
    return(EXIT_SUCCESS);
}
