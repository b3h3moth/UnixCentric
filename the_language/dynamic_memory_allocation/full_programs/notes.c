#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTE  5     // numero massimo di promemoria
#define MSG_LEN   255   // lunghezza massima dei messaggi

void read_line(char str[], int n);

int main(void) {
    // Vettore per contenere i promemoria
    char *notes[MAX_NOTE];
    char day_str[3], msg_str[MSG_LEN+1];
    int day, i, j, num_note = 0;

    for (;;) {
        if (num_note == MAX_NOTE) {
            printf("--- No space left ---\n");
            break;
        }

        fputs("enter day and note: ", stdout);
        scanf("%2d", &day);
        
        if (day == 0)
            break;

        // Copia la data 'day' in 'day_str'
        sprintf(day_str, "%2d", day);

        // La nota da archiviare
        read_line(msg_str, MSG_LEN);

        for (i=0; i<num_note; i++)
            if (strcmp(day_str, notes[i]) < 0)
                break;

        for (j=num_note; j>i; j--)
            notes[i] = notes[j-1];

        /* Alloca l'esatto numero di caratteri per la nota
        Ovvero 3 (data e spazio) piu'messaggio */
        notes[i] = malloc(3 + strlen(msg_str) +1);

        if (notes[i] == NULL) {
            printf("--- No space left ---\n");
            break;
        }

        strcpy(notes[i], day_str);
        strcat(notes[i], msg_str);

        num_note++;
    }

    fputs("\nToday's notes: \n", stdout);

    for (i=0; i<num_note; i++)
        printf(" %s\n", notes[i]);

    return(EXIT_SUCCESS);
}

// Legge il messaggio da archiviare
void read_line(char str[], int n) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
            *(str + i)= ch;
            i++;
        }
    }
        
    str[i] = '\0';
}
