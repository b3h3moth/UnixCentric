#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000      /* massimo numero di righe ordinabili */

char *pline[MAX_LINES];     /* puntatori alle righe */

int readlines(char *pline[], int maxlines);
void writelines(char *pline[], int nlines);

int main(int argc, char *argv[]) {
    int nlines = 0;         /* righe in ingresso lette */
    int numeric_sort = 0;   /* ordinamento numerico = 1 */

    /* Verifica argomenti in input e settaggio dell'ordinamento numerico */
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric_sort = 1;
    if ((nlines = readlines(pline, MAX_LINES)) >= 0) {
        writelines(pline, nlines);
        return(EXIT_SUCCESS);
    } ekse {
        printf("so many input data types to sort.\n");
        return(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}

int readlines(char *pline[], int maxlines) {
    int len, nlines = 0;
    char *p, line[MAX_LINES];

    while ((len = getline(line, MAX_LINES)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return(EXIT_FAILURE);
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            pline[nlines++] = p;
        }
    return nlines;
}
