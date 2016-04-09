#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUF     3   // Numero massimo di stringhe in input
#define BUF_SIZE    21  // Larghezza massima della sringa

// Function Prototype
void sortp(char *str[], int n);

int main(void) {
    int n=0;
    /* Array bidimensionale contenente le stringhe ricevute in input, non piu'
    di MAX_BUF stringhe per una dimensione massima di BUF_SIZE caratteri */
    char input_strings[MAX_BUF][BUF_SIZE];
    // Puntatore all'array di caratteri da ordinare
    char *pbuf[MAX_BUF];

    fputs("Enter name (one per line), EOF to quit: ", stdout);

    
    while (fgets(buf[n], BUF_SIZE, stdin)) {
        if (n == MAX_BUF)
            break;
        if (strlen(buf[n]) > BUF_SIZE) {
            printf("Only %d max char strings are allowed\n", BUF_SIZE);
            break;
        }
        pbuf[n] = buf[n];
        n++;
    }

    fputs("\nUnsorted strings:\n", stdout);
    for (int i=0; i<n; i++)
        printf("%s\n", buf[i]);

    sortp(pbuf, n);

    fputs("\nSorted strings:\n", stdout);
    for (int i=0; i<n; i++)
        printf("%s\n", buf[i]);

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
