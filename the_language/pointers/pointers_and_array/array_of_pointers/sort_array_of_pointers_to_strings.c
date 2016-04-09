#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUF     5   // Numero massimo di stringhe in input
#define BUF_SIZE    21  // Larghezza massima della sringa

// Function Prototype
void sortp(char *str[], int n);

int main(void) {
    int n;
    char buf[MAX_BUF][BUF_SIZE];
    char *pbuf[MAX_BUF];

    fputs("Enter name (one per line), EOF to quit: ", stdout);

    for (n = 0; fgets(buf[n], BUF_SIZE, stdin) && n < MAX_BUF; n++) {
        //buf[n][strlen(buf[n])-1] = '\0';
        pbuf[n] = buf[n];
    }

    fputs("\nUnsorted strings:\n", stdout);
    for (int i=0; i<n; i++)
        printf("%s\n", buf[i]);

    return(EXIT_SUCCESS);
}

void sortp(char *str[], int n) {
    int maxpos = 0;
    char *tmp;

    for (int size = n; size>1; size--) {
        for (int i=0; i<size; i++)
            if (strcmp(str[i], str[maxpos]) > 0)
                maxpos = i;
        tmp = str[maxpos];
        str[maxpos] = str[size-1];
        str[size-1] = tmp;
    }
}
