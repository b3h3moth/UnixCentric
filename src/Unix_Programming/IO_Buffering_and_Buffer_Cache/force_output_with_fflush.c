#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Lo scopo del programma e' di forzare la scrittura dell'output mediante
l'utilizzo della funzione fflush() e di verificare il line-buffering mediante
la semplice aggiunta di una newline per consentire la scrittura su terminale.
*/

int main(void) {

    /* La funzione write() invia i propri dati direttamente alla buffer cache
    del kernel, la printf() invece attende che il buffer di userspace sia pieno
    prima di inviare i dati alla medesima buffer cache del kernel per essere
    scritti.

    Va da sè che, nel caso specifico, l'output scritto sul terminale potrebbe
    subire delle variazioni consistenti. */
    printf("Take a walk on the wild side, by: ");
    write(1, "Lou Reed.\n", 10);

    fputc('\n', stdout);

    /* Per risolvere il problema sopra esposto si utilizza la fflush() per
    scaricare i dati, ovvero il buffer, in output. */
    printf("Get-up stand-up, stand-up for your rights, by: ");
    fflush(stdout);
    write(1, "Bob Marley.\n", 12);

    fputc('\n', stdout);

    /* Da notare ulteriormente che i file associati al terminale, ovvero
    stdin 0 e stdout 1, sono line-buffered piuttosto che fully-buffered, per
    cui l'output non sara' scritto fintanto che o il buffer non sia pieno o che
    si incontri una newline.

    Da notare che l'altro file associato al terminale, stderr 2, e'
    not-buffered. */
    printf("Back in black: \n"); // Con la newlline finale
    write(1, "AC/DC.\n", 7);

    return(EXIT_SUCCESS);
}
