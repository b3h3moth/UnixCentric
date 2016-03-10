#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

char lyrics[][MAX_LEN] = { 
        "No, we don't need no more trouble",
        "Getup stand up standup for your rights",
        "I shot the sheriff but I didn't shoot no deputy",
        "Stop that train, I'm leavin today",
        "The zion train is coming our way",
        "There's natural mystic blowing through the air"
};

/* Lo scopo del programma e' di verificare il funzionamento della funzione
strstr() */

void find_str(char str[]);
void remove_newline(char str[]);

int main(void) {
    char buf[MAX_LEN];

    printf("Search: ");
    fgets(buf, MAX_LEN, stdin);

    for (int i=0; i<strlen(buf); i++) {
        if (buf[i] == '\n') {
            buf[i] = '\0';
            break;
        }
    }
    
    find_str(buf);

    return(EXIT_SUCCESS);
}

void find_str(char str[]) {
    for (int i=0; i<sizeof(lyrics)/sizeof(lyrics[0]); i++)
        if (strstr(lyrics[i], str)) {
            printf("Lyric %d: %s\n", i, lyrics[i]);
        }
}

void remove_newline(char str[]) 
