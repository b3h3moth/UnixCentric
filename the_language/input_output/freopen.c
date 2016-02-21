#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

/* Lo scopo del programma e' redirigere lo stream output verso un file mediante
la funzione freopen(), dopodiche' scrivere nel file stesso una stringa che 
identifichi la data esatta della scrittura della stringa stessa. 
Tale esempio puo' essere un buon punto di partenza per la realizzazione di 
routine di debugging e/o testing. */

int main(void) {
    time_t t;
    char *date;
    char fname[] = "data.txt";

    if (time(&t) < 0) {
        fprintf(stderr, "Err. %d time(); %s.\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fputs("Before freopen()\n", stdout);

    if (freopen(fname, "w", stdout) == NULL) {
        fprintf(stderr, "Unable to redirect stdout stream.\n");
        exit(EXIT_FAILURE);
    } else {
        if ((date = ctime(&t)) == NULL) {
            fprintf(stderr, "Err. %d ctime(); %s.\n", errno, strerror(errno));
            exit(EXIT_FAILURE);
        }

        /* La funzione ctime() aggiunge un carattere di new-line alla fine
        della stringa creata. L'istruzione di seguito sostituisce tale
        carattere con un piu' congruo null-terminated character. */
        date[strlen(date)-1] = '\0';
        
        printf("Line executed at: \'%s\'\n", date);
    }

    /* Redirige lo stream output allo stato originale.
    Nota: Questa soluzione non funziona sempre e non e' portabile. */
    freopen("/dev/tty", "a", stdout);

    fputs("After freopen()\n", stdout);

    return(EXIT_SUCCESS);
}
