#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

/* Sui sistemi UNIX il modo piu' semplice per allocare memoria dinamicamente
e' mediante le syscalls brk() e sbrk() che consentono la gestione e il relativo
innalzamento del 'program break'.

HEADER    : <unistd.h>
PROTOTYPE : void *sbrk (intptr_t increment);

La funzione sbrk() consente di incrementare e/o decrementare il valore corrente
del 'program break' mediante un offset intero specificato da 'increment'; 
va da se che incrementare sta per allocare memoria, decrementare invece sta per
deallocare. Ritorna il valore del 'program break' in caso di esito positivo,
-1 nel caso fallisse. La chiamata sbrk(0) restituisce la locazione corrente 
del 'program break'.
*/

/* Lo scopo del programma e' di incrementare il 'program break' di 10 byte,
di salvare il suo valore prima e dopo la chiamata alla system call e infine
stampare in output i relativi valori. */

int main(void) {
    const intptr_t size_incr = 10;
    void *pb_old_addr, *pb_current_addr;

    // Si ottiene il valore corrente del 'program 'break'
    if ( (pb_old_addr = sbrk(0)) == (void *) - 1) {
        fprintf(stderr, "Err.(%d) sbrk(): %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
