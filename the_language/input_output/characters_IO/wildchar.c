#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Lo scopo del programma e' di leggere uno o piu' file in input e di stampare
su stdout il/i file compresi alcuni caratteri speciali */

int main(int argc, char *argv[]) {
    int ch;
    int strip = 0; // taglia dalla visione i caratteri speciali

    if (argc > 1 && strcmp(argv[1], "-s") == 0)
        strip = 1;

    while ((ch = getchar()) != EOF) {
        if (isascii(ch) && (isprint(ch) || ch == '\n' || ch == '\t' || ch == ' '))
            putchar(ch);
        else if (!strip)
            printf("\\%03o", ch);
    }

    return(EXIT_SUCCESS);
}
