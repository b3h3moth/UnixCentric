#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del programma e' di utilizzare una funzione inline per la gestione
degli eventuali errori */

static inline void err_msg(int status, const char *msg);

int main(void) {
    return(EXIT_SUCCESS);
}

static inline void err_msg(int status, const char *msg) {
    fputs(msg, stderr);
    exit(status);
}
