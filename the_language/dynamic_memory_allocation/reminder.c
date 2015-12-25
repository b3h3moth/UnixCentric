#include <stdio.h>
#include <stdlib.h>

#define MAX_REMIND  50  // numero massimo di promemoria
#define MSG_LEN     60  // lunghezza massima dei messaggi

int read_line(char str[], int n);

int main(void) {
    return(EXIT_SUCCESS);
}

int read_line(char str[], int n) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
        str[i] = '\0';
    }

    return i;
}

