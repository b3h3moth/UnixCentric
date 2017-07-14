#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000      /* massimo numero di righe ordinabili */
#define ALLOC_SIZE 100     /* Spazio disponibile */

static char allocbuf[ALLOC_SIZE];   /* vettore di memoria */
static char *palloc = allocbuf;     /* primo elemento libero */
char *pline[MAX_LINES];             /* puntatori alle righe */

int readlines(char *pline[], int maxlines);
void writelines(char *pline[], int nlines);
char *alloc(int n);
void afree(char *p);

int main(int argc, char *argv[]) {
    int nlines = 0;         /* righe in ingresso lette */
    int numeric_sort = 0;   /* ordinamento numerico = 1 */

    /* Verifica argomenti in input e settaggio dell'ordinamento numerico */
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric_sort = 1;
    if ((nlines = readlines(pline, MAX_LINES)) >= 0) {
        writelines(pline, nlines);
        return(EXIT_SUCCESS);
    } else {
        printf("so many input data types to sort.\n");
        return(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}

int readlines(char *pline[], int maxlines) {
    int len, nlines = 0;
    char *p, line[MAX_LINES];

    while ((len = getline(line, MAX_LINES)) > 0)
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return(EXIT_FAILURE);
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            pline[nlines++] = p;
        }
    return nlines;
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
