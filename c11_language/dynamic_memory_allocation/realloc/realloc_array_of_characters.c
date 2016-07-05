#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototype
char *get_line(void);
char *trim(char *msg);

/* Lo scopo del programma e' l'implementazione della funzione get_line() che
dopo la lettura di caratteri dallo stdin li assegna a un buffer, ma poiche' il
totale dei caratteri non e' noto, si utilizza la funzione realloc() per
assegnare lo spazio necessario. Lo scopo della funzione trim() invece e' di 
eliminare dalla stringa ottenuta in input gli spazi vuoti. */

int main(void) {
    char *text = get_line();
    printf("%s %d\n", text, strlen(text));

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
        if (++len >= max_len) {
            char *new_buf = realloc(buf, max_len += size_increment);

            // Se il nuovo buffer e' vuoto ritorna NULL e libera la memoria
            if (new_buf == NULL) {
                free(new_buf);
                return NULL;
            }

            /* La posizione corrente e' orientata a puntare nella giusta posizione
            del nuovo buffer, dopodiche' si fa puntare il buffer originario al
            nuovo buffer */
            cur_pos = new_buf + (cur_pos - buf);
            buf = new_buf;
        }
        
        *cur_pos++ = ch;
    }
    // Aggiunta del 'null-character' alla fine del buffer
    *cur_pos = '\0';
    return buf;
}

char *trim(char *msg) {
