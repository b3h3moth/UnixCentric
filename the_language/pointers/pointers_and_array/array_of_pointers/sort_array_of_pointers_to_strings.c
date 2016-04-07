#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUF     5   // Numero massimo di stringhe in input
#define BUF_SIZE    21  // Larghezza massima della sringa

int main(void) {
    int n, i;
    char buf[MAX_BUF][BUF_SIZE];
    char *pbuf[MAX_BUF];

    fputs("Enter name (one per line), EOF to quit: ", stdout);

    for (n = 0; fgets(buf[n], MAX_BUF, stdin) && n < MAX_BUF; n++) {
        pbuf[n] = buf[n];
    }

    fputs("Unsorted strings", stdout);
    for (int i=0; i<n; i++)
        printf("%s\n", buf[i]);

    return(EXIT_SUCCESS);
}
