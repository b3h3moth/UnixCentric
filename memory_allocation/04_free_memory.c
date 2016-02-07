#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>

/* Lo scopo del programma e' di allocare 32 byte di memoria, dopodiche'
deallocarli */

int main(int argc, char *argv[]) {
    void *addr;
    intptr_t size_incr = 32;

    // Salva il valore corrente del 'program break'
    if ((addr = sbrk(0)) == (void *)-1) {
        fprintf(stderr, "Err.(%d) sbrk(0): %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Current program break address: %p\n", addr);

    // Incrementa il 'program break' di 'size_incr' byte
    if (brk(((uint8_t*)addr + size_incr)) == -1 ) {
        fprintf(stderr, "Err.(%d) brk(): %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }


    // Libera la memoria precedentemente allocata
    if (brk(addr) == -1) {
        fprintf(stderr, "Err.(%d) brk(): %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
