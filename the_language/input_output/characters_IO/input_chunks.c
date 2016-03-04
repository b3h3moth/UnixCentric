#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define PAGE_SIZE 22

// Function prototype
FILE *openfile(char *file, char *mode);
void print(FILE *fp, int pgsize);
void opentty(void);

/* Lo scopo del programma e' di leggere lo standard input una pagina alla
volta. La dimensione della pagina e' ottenuta mediante il conteggio delle
linee di input ed e' definita da pgsize. Per andare avanti nella lettura
della pagina successiva e' sufficiente 'return', oppure 'q' per uscire 
immediatamente. */

int main(int argc, char *argv[]) {
    FILE *fp;
    int page_size = PAGE_SIZE;  // Valore di default dimensione pagina

    fp = openfile(argv[1], "r");
    print(fp, PAGE_SIZE);

    return(EXIT_SUCCESS);
}

/* Apre uno stream in lettura, in caso di successo restituisce al chiamante un
puntatore allo stream, altrimenti esce */
FILE *openfile(char *file, char *mode) {
    FILE *fp;

    if ((fp = fopen(file, mode)) != NULL)
        return fp;
    else {
        fprintf(stderr, "Err. fopen() %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

/* Stampa sullo standard output una pagina, dopodiche' ogni scheramata sara'
passata a opentty() */
void print(FILE *fp, int pgsize) {
    static int lines = 0;
    char buf[BUFSIZ];       // La grandezza del buffer di input

    while (fgets(buf, sizeof(buf), fp) != NULL)
        if (++lines < pgsize) {
            fputs(buf, stdout);
        } else {
            buf[strlen(buf)-1] = '\0';
            fflush(stdout); // Pulisce lo schermo ad ogni pgsize -1
            opentty();      // Legge il resto delle pagine
            lines = 0;      // Azzera il conteggio delle linee
        }
}

/* Ciascuna nuova pagina da leggere, successiva alla prima, viene inviata
al device '/dev/tty' */
void opentty(void) {
    char buf[BUFSIZ];
    static FILE *tty = NULL;

    if (tty == NULL)
        tty = openfile("/dev/tty", "r");
    if (fgets(buf, BUFSIZ, tty) == NULL || buf[0] == 'q')
        exit(EXIT_FAILURE);
}
