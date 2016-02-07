#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>

/* Lo scopo del programma e' di scrivere la stringa "Hello World" a partire
dall'indirizzo iniziale della heap, ovvero dal program break, dopodiche'
stampare la stringa sia carattere per carattere sia come stringa unica. */

int main(int argc, char *argv[]) {
    void *pb_old_addr, *pb_cur_addr;
    intptr_t size_incr = 12;

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

    // Setta la stringa carattere per carattere
    *((char *)pb_old_addr) = 'H';
    *((char *)pb_old_addr + 1) = 'e';
    *((char *)pb_old_addr + 2) = 'l';
    *((char *)pb_old_addr + 3) = 'l';
    *((char *)pb_old_addr + 4) = 'o';
    *((char *)pb_old_addr + 5) = ' ';
    *((char *)pb_old_addr + 6) = 'W';
    *((char *)pb_old_addr + 7) = 'o';
    *((char *)pb_old_addr + 8) = 'r';
    *((char *)pb_old_addr + 9) = 'l';
    *((char *)pb_old_addr + 10) = 'd';
    *((char *)pb_old_addr + 11) = '\0';

    //  Stampa 'char by char'
    for (int i=0; i<size_incr; i++)
        printf("%c", *((char *)pb_old_addr + i));

    // Stampa la fornendo come indirizzo iniziale il vecchio 'program break'
    printf("\n%s\n", (char *)pb_old_addr);

    return(EXIT_SUCCESS);
}
