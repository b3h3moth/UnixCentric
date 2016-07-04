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
    // Grandezza iniziale del buffer, nonche' l'incremento del buffer stesso
    const size_t size_increment = 10;
    // Puntatore al buffer dei caratteri letti dallo stdin
    char *buf = malloc(size_increment);
    // Puntatore alla successiva posizione libera nel buffer
    char *cur_pos = buf;
    // Massimo numeri di caratteri che possono essere collocati nel buffer
    size_t max_len = size_increment;
    // Numero di caratteri letti
    size_t len = 0;
    // Ultimo carattere letto
    int ch;

    // Se il buffer e' vuoto ritorna NULL
    if (cur_pos == NULL)
        return NULL;

    while(1) {
        // Legge i caratteri dallo standard input
        ch = fgetc(stdin);

        // Non appena ci si imbatte in una new-line il ciclo termina
        if (ch == '\n')
            break;

        /* Se si supera il valore di incremento iniziale si procede a
        riallocare la memoria in un nuovo buffer */
        if (++len >= max_len)
            char *new_buf = realloc(buf, max_len += size_increment);

        // Se il nuovo buffer e' vuoto ritorna NULL e libera la memoria
        if (new_buf == NULL) {
            free(new_buf);
            return NULL;
        }
    }
}
