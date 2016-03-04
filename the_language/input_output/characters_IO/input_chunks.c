#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define PAGE_SIZE 22

// Function prototype
FILE *openfile(char *file, char *mode);
void print(FILE *fp, int page_size);
void opentty(void);

/* Lo scopo del programma e' di leggere l'input una pagina alla volta, la
dimensione della pagina, in righe naturalmente, e' definita da PAGE_SIZE */

int main(int argc, char *argv[]) {
    char *program_name;
    FILE *fp;

    fp = openfile(argv[1], "r");
    print(fp, PAGE_SIZE);

    return(EXIT_SUCCESS);
}

/* Apre un file, se ci riesce il puntatore al file sara' restituito al 
chiamante, altrimenti esce */
FILE *openfile(char *file, char *mode) {
    FILE *fp;

    fp = fopen(file, mode);

    if (fp != NULL)
        return fp;
    else {
        fprintf(stderr, "Err. fopen() %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

/* Stampa PAGE_SIZE -1 linee in output, dopodiche' ogni scheramata sara'
passata a opentty() */
void print(FILE *fp, int page_size) {
    static int lines = 0;
    char buf[BUFSIZ];       // La grandezza del buffer di input

    while (fgets(buf, sizeof(buf), fp) != NULL)
        if (++lines < page_size) {
            fputs(buf, stdout);
        } else {
            buf[strlen(buf)-1] = '\0';
            fflush(stdout); // Pulisce lo schermo ad ogni PAGE_SIZE -1
            opentty();       // Legge il resto delle pagine
            lines = 0;      // Azzera il conteggio delle linee
        }
}

// Invia le pagine a /dev/tty per la gestione della lettura
void opentty(void) {
    char buf[BUFSIZ];
    static FILE *tty = NULL;

    if (tty == NULL)
        tty = openfile("/dev/tty", "r");
    if (fgets(buf, BUFSIZ, tty) == NULL || buf[0] == 'q')
        exit(EXIT_FAILURE);
}
