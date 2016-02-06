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

/* Lo scopo del programma e' di salvare il 'program break' corrente, 
incrementare la memoria mediante un valore ricevuto in input, stampare il nuovo
'program break'. */

int main(int argc, char *argv[]) {
    void *pb_old_addr, *pb_cur_addr;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <size>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    intptr_t size_incr = strtol(argv[1], NULL, 10);



    return(EXIT_SUCCESS);
}
