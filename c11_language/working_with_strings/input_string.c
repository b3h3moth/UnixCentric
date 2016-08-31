#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 50

/* Lo scopo del programma e' di ricevere una stringa in input e costruirla
come tale mediante un vettore di caratteri della medesima lunghezza */

int main(void) {
    char ch, buf[MAX_BUF];
    unsigned i = 0;
    
    printf("Type a string: ");
    while ((ch = getchar()) != '\n') {
        if (i < MAX_BUF-1)
            buf[i++] = ch;
        else {
            printf("Sorry, the string is too large.\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("%s\n", buf);

    return(EXIT_SUCCESS);
}
