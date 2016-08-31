#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del programma e' di utilizzare una funzione inline per la gestione
degli eventuali errori */

static inline void err_msg(int status, const char *msg);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        err_msg(1, "Error Message.");
    }

    return(EXIT_SUCCESS);
}

static inline void err_msg(int status, const char *msg) {
    fprintf(stderr, "%s (exit status: %d)\n", msg, status);
    exit(status);
}
