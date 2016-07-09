#include <stdio.h>
#include <stdlib.h>

enum {BUF_SIZE = 10};

// Function Prototypes
void init_buffer(char *buf, size_t size);
static void print_buffer(char *buf);

/* La funzione snprintf() e' la versione piu' sicura della funzione sprintf(),
che si consiglia di non usare o comunque di adoperarla con particolare 
accortezza poiche' e' particolarmente soggetta ad errori quali il
'buffer overflow'. La peculiarita' della funzione snprintf() rispetto alla 
sprintf() sta proprio nella possibilita' di poter indicare la grandezza del
buffer.

Signature: int snprintf(char *str, size_t size, const char *format, ...)
Semantics: La funzione snprintf() redirige al massimo 'size' byte dell'output 
della printf() nel buffer 'str', compreso '\0'; 'format' si occupa del formato
della stringa all'interno del buffer 'str'; infine '...' sono gli argomenti 
opzionali.
Returns: Ritorna il numero dei caratteri scritti in 'str', escluso '\0'.
*/

int main(void) {
    char buf[BUF_SIZE];

    init_buffer(buf, BUF_SIZE);
    print_buffer(buf);

    init_buffer(buf, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "I Love C");
    print_buffer(buf);

    init_buffer(buf, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "Hi");
    print_buffer(buf);

    init_buffer(buf, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "Take a Walk on the wild side");
    print_buffer(buf);

    init_buffer(buf, BUF_SIZE);
    snprintf(buf, 5, "%d", 11111);
    print_buffer(buf);

    init_buffer(buf, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "%d:%s:%d", 10, "hi", 10);
    print_buffer(buf);

    return(EXIT_SUCCESS);
}

// Inizializza un vettore di 'size' elementi
void init_buffer(char *buf, size_t size) {
    int i;

    for (i=0; i<size; i++)
        *(buf + i) = i + '0';

}

// Stampa ciascun elemento del vettore
static void print_buffer(char *buf) {
    int i;
    char c;

    for (i=0; i<BUF_SIZE; i++) {
        c = *(buf + i);
        if (c == '\0') {
            printf("\\0");
        } else 
            printf("%c", *(buf +i));
    }
    printf("\n");
}
