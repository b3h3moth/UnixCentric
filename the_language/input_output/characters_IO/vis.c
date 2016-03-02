#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Lo scopo del programma e' di leggere uno o piu' file in input e di stampare
su stdout i caratteri speciali */

int main(int argc, char *argv[]) {
    int ch;
    int show = 0; // mostra caratteri speciali se attivata

    if (argc > 1 && strcmp(argv[1], "-s") == 0)
        show = 1;

    while ((ch = getchar()) != EOF) {
        if (show)
            printf("\\%03o", ch);
        else if (isascii(ch) && (isprint(ch) || ch == '\n' || ch == '\t' || ch == ' '))
            fputc(ch, stdout);
    }

    return(EXIT_SUCCESS);
}
