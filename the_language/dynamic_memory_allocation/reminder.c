#include <stdio.h>
#include <stdlib.h>

#define MAX_REMIND  50  // numero massimo di promemoria
#define MSG_LEN     60  // lunghezza massima dei messaggi

int read_line(char str[], int n);

int main(void) {
    // Vettore per contenere i promemoria
    char *reminders[MAX_REMIND];
    char day_str[3], msg_str[MSG_LEN+1];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("--- No space left ---\n");
            break;
        }

        fputs("enter day and reminder"

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

