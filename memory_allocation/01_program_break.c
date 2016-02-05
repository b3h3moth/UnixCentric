#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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


int main(void) {
    return(EXIT_SUCCESS);
}
