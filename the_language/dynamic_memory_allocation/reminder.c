#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        fputs("enter day and reminder: ", stdout);
        scanf("%2d", &day);
        
        if (day == 0)
            break;

        // Copia 'day' in 'day_str'
        sprintf(day_str, "%2d", day);

        read_line(msg_str, MSG_LEN);

        for (i=0; i<num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;

        for (j=num_remind; j>i; j--)
            reminders[i] = reminders[j-1];

        // Alloca l'esatto numero di caratteri per il reminder
        reminders[i] = malloc(2 + strlen(msg_str) +1);

        if (reminders[i] == NULL) {
            printf("--- No space left ---\n");
            break;
        }


    }

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

