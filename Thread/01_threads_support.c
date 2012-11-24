#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/* Per verificare se il sistema supporta i thread vi sono due strade:

1 - a compile-time, utilizzando le direttive al preprocessore per la 
    compilazione condizionale, nel caso specifico la macro _POSIX_THREADS; 

2 - a run-time, mediante la funzione sysconf e la costante _SC_THREADS. */

int main(void) {
    long res;

#ifdef _POSIX_THREADS
    printf ("POSIX.1c pthreads supportati\n");
#endif

    if ((res = sysconf(_SC_THREADS)) == -1) {
        fprintf(stderr, "Err.(%d) - sysconf; %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("System support threads: %li\n", res);

    return(EXIT_SUCCESS);
}
