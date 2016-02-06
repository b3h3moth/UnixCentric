#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* La syscall brk() lavora diversamente rispetto alla syscall sbrk().

HEADER    : <unistd.h>
PROTOTYPE : int brk(void *address);

brk() imposta il 'program break' all'indirizzo specificato da 'address', in 
altre parole setta la fine del segmento data (BSS) all'indirizzo 'address'. 
Ritorna 0 in caso di successo, -1 in caso di errore. 

Sia malloc() sia sbrk() sono implementate sopra brk(). */

int main(void) {
    return(EXIT_SUCCESS);
}
