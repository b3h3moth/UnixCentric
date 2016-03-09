#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 40

/* Lo scopo del programma e' di verificare il funzionamento della funzione
strstr() */

void find_str(char str[]);

int main(void) {
    char lyrics[][MAX_LEN] = { 
        "take a walk on the wild side",
        "getup stand up standuo for your rights",
        "could you be loved",
        "The zion train is coming our way"
    };

    return(EXIT_SUCCESS);
}

void find_str(char str[]) {
    for (int i=0; i<4; i++)
        if (strstr(str[i], find_str()))
            printf("Lyric %d: %s\n", i, str[i]);
}
