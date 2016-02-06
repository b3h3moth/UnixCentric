#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>

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

    // Salva il valore corrente del 'program break'
    if ((pb_old_addr = sbrk(0)) == (void *)-1) {
        fprintf(stderr, "Err.(%d) old sbrk(0): %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Incrementa il 'program break' di 'size_incr' byte
    if (brk(((uint8_t*)pb_old_addr + size_incr)) == -1 ) {
        fprintf(stderr, "Err.(%d) brk(): %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Salva nuovamente il valore corrente del 'program break'
    if ((pb_cur_addr = sbrk(0)) == (void *)-1) {
        fprintf(stderr, "Err.(%d) cur sbrk(0): %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("    (old) 'program break' address: %p\n", pb_old_addr);
    printf("(current) 'program break' address: %p\n", pb_cur_addr);

    return(EXIT_SUCCESS);
}
