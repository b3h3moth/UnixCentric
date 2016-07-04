#include <stdio.h>
#include <stdlib.h>

// Function Prototype
char *get_line(void);

/* Lo scopo del programma e' l'implementazione della funzione get_line() che
dopo la lettura di caratteri dallo stdin, li assegna a un buffer, ma poiche' il
totale dei caratteri stesso non e' noto, si utilizza la funzione realloc() per
assegnare lo spazio necessario. */

int main(void) {
    return(EXIT_SUCCESS);
}

char *get_line(void) {
    // La grandezza iniziale del buffer, nonche' l'incremento del buffer stesso
    const size_t size_increment = 10;
