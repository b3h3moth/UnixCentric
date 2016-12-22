#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

/* Lo scopo del programma e' di convertire un dato broken-down time in una
stringa */

int main(void) {
    struct tm *ptm;
    time_t t;
    char *str_time;
   
    if ((t = time(NULL)) < 0) {
       fprintf(stderr, "Err.(%s) getting time\n", strerror(errno));
       exit(EXIT_FAILURE);
    }

    if ((ptm = gmtime(&t)) == NULL) {
       fprintf(stderr, "Err.(%s) conversion gmtime()\n", strerror(errno));
       exit(EXIT_FAILURE);
    }
  
    if ((str_time = asctime(ptm)) == NULL) {
       fprintf(stderr, "Err.(%s) str conversion: asctime()\n", strerror(errno));
       exit(EXIT_FAILURE);
    }
    
    printf("%s", str_time);
    
    return(EXIT_SUCCESS);
}
