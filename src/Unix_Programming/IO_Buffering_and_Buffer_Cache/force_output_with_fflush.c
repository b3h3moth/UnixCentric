#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Lo scopo del programma e' di forzare la scrittura dell'output mediante
l'utilizzo della funzione fflush(). */

int main(void) {

    /* la funzione write() invia i propri dati direttamente al buffer cache del
    kernel, la printf() invece attende che il buffer di userspace sia pieno
    prima di inviare i dati al buffer cache del kernel per essere scritti.

    Va da sè che, nel caso specifico, l'output sara' invertito */
    printf("Take a walk on the wild side, by: ");
    write(1, "Lou Reed.\n", 10);

    fputc('\n', stdout);

    /* Per risolvere il problema sopra citato si utilizza la fflush() per
    scrivere immediatamente i dati in output. */
    printf("Get-up stand-up, stand-up for your rights, by: ");
    fflush(stdout);
    write(1, "Bob Marley.\n", 12);

    return(EXIT_SUCCESS);
}
