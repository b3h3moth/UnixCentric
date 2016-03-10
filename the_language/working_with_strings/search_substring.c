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
void remove_newline(char *str);

int main(void) {
    char buf[MAX_LEN];

    fputs("Search: ", stdout);
    
    if (fgets(buf, MAX_LEN, stdin) == NULL) {
        fprintf(stderr, "Err. when working with string %s\n", buf);
        exit(EXIT_FAILURE);
    }

    remove_newline(buf);
    find_str(buf);

    return(EXIT_SUCCESS);
}

void find_str(char str[]) {
    for (int i=0; i<sizeof(lyrics)/sizeof(lyrics[0]); i++)
        if (strstr(lyrics[i], str)) {
            printf("Lyric %d: %s\n", i+1, lyrics[i]);
        }
}

void remove_newline(char *str) {
    for (int i=0; i<strlen(str); i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}
