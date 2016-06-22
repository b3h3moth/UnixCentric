#include <stdio.h>
#include <stdlib.h>

enum {BUF_SIZE = 19};

// Function Prototypes
void init_buffer(char *buf, size_t size);

/*
HEADER: int snprintf(char *str, size_t size, const char *format, ...);

SEMANTICS: La funzione snprintf() redirige al massimo 'size' byte dell'output 
della printf() nel buffer 'str', compreso '\0'; 'format' si occupa di gestire 
il formato della stringa all'interno del buffer 'str' - %s, %d, %f etc.; 
infine '...' sono gli argomenti opzionali.

RETURNS: Il numero dei caratteri scritti in 'str', escluso '\0'.
*/

int main(void) {
    char buf[BUF_SIZE];

    init_buffer(buf, BUF_SIZE);

    return(EXIT_SUCCESS);
}

// Inizializza un vettore di 'size' elementi
void init_buffer(char *buf, size_t size) {
    int i;

    for (i=0; i<size; i++)
        *(buf + i) = i*i;
}
