#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTE  100  // numero massimo di promemoria
#define MSG_LEN     255  // lunghezza massima dei messaggi

void read_line(char str[], int n);

int main(void) {
    // Vettore per contenere i promemoria
    char *notes[MAX_NOTE];
    char day_str[3], msg_str[MSG_LEN+1];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_NOTE) {
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
            if (strcmp(day_str, notes[i]) < 0)
                break;

        for (j=num_remind; j>i; j--)
            notes[i] = notes[j-1];

        /* Alloca l'esatto numero di caratteri per il reminder
        Ovvero 3 (data e spazi) piu'messaggio */
        notes[i] = malloc(3 + strlen(msg_str) +1);

        if (notes[i] == NULL) {
            printf("--- No space left ---\n");
            break;
        }

        strcpy(notes[i], day_str);
        strcat(notes[i], msg_str);

        num_remind++;
    }

    fputs("\nDay reminder\n", stdout);

    for (i=0; i<num_remind; i++)
        printf(" %s\n", notes[i]);

    return(EXIT_SUCCESS);
}

void read_line(char str[], int n) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
        str[i] = '\0';
}

