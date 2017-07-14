#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000      /* massimo numero di righe ordinabili */
#define ALLOC_SIZE 10000     /* Spazio disponibile */

static char allocbuf[ALLOC_SIZE];   /* vettore di memoria */
static char *palloc = allocbuf;     /* primo elemento libero */
char *pline[MAX_LINES];             /* puntatori alle righe */

int read_lines(char *pline[], int maxlines);
void write_lines(char *pline[], int nlines);
int get_line(char str[], int lim);
char *alloc(int n);
void afree(char *p);

int main(int argc, char *argv[]) {
    int nlines = 0;         /* righe in ingresso lette */
    int numeric_sort = 0;   /* ordinamento numerico = 1 */

    /* Verifica argomenti in input e settaggio dell'ordinamento numerico */
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric_sort = 1;
    if ((nlines = read_lines(pline, MAX_LINES)) >= 0) {
        write_lines(pline, nlines);
        return(EXIT_SUCCESS);
    } else {
        printf("so many input data types to sort.\n");
        return(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}

/* La funzione read_lines() legge le righe in entrata */
int read_lines(char *pline[], int maxlines) {
    int len, nlines = 0;
    char *p, line[MAX_LINES];

    while ((len = get_line(line, MAX_LINES)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return(EXIT_FAILURE);
        else {
            line[len-1] = '\0';
            strlcpy(p, line, len);
            pline[nlines++] = p;
        }
    return nlines;
}

/* La funzione write_lines() scrive le righe in uscita */
void write_lines(char *pline[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *pline++);
}

/* Leggere la riga ingresso, la copia in 'str' ritornando la lunghezza */
int get_line(char str[], int lim) {
    int c, i;

    for (i=0; i<lim-1 && (c = getchar()) != EOF && c!= '\n'; ++i)
        str[i] = c;
    if (c == '\n') {
        str[i] = c;
        ++i;
    }
    str[i] = '\0';
    
    return i;
}

/* La funzione alloc() restituisce un puntatore a n caratteri */
char *alloc(int n) {
    if (allocbuf + ALLOC_SIZE - palloc >= n) {
        palloc += n;
        return palloc -n;
    } else
        return 0;
}

/* Libera la memoria puntata da p */
void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOC_SIZE)
        palloc = p;
}
