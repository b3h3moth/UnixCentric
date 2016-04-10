#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUF     10   // Numero massimo di stringhe in input
#define BUF_SIZE    21  // Larghezza massima della sringa

// Function Prototype
void sortp(char *str[], int n);

/* Lo scopo del programma e' di salvare in un array bidimensionale un totale di
MAX_BUF stringhe ottenute dallo standard input e al contempo assegnare a ogni 
elemento di un array di puntatori l'indirizzo di una stringa. Infine ordinare 
le stringhe con la funzione sortp(), lavorando coi puntatori mediante un 
algoritmo 'selection sort'. */

int main(void) {
    /* Array bidimensionale contenente le stringhe ricevute in input, non piu'
    di MAX_BUF stringhe per una dimensione massima di BUF_SIZE caratteri */
    char buf[MAX_BUF][BUF_SIZE];
    // Puntatore all'array di caratteri da ordinare
    char *pbuf[MAX_BUF];
    size_t n=0;

    printf("Enter string (max %d size)\n", BUF_SIZE-1);
    fputs("> ", stdout);

    for (int j=0; j<MAX_BUF; j++) {
        fgets(buf[n], BUF_SIZE-1, stdin);
            buf[n][strlen(buf[n])-1] = '\0';
        pbuf[n] = buf[n];
        n++;
    }

    fputs("\nUnsorted strings:\n", stdout);
    for (int i=0; i<n; i++)
        printf("%s\n", buf[i]);

    sortp(pbuf, n);

    fputs("\nSorted strings:\n", stdout);
    for (int i=0; i<n; i++)
        printf("%s\n",pbuf[i]);

    return(EXIT_SUCCESS);
}

void sortp(char *str[], int n) {
    int maxpos = 0, i, size;
    char *tmp;

    for (size = n; size>1; size--) {
        for (i=0; i<size; i++)
            if (strcmp(str[i], str[maxpos]) > 0)
                maxpos = i;
        tmp = str[maxpos];
        str[maxpos] = str[size-1];
        str[size-1] = tmp;
    }
}
