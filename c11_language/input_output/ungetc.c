#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Lo scopo del programma e' di convertire le cifre decimali ricevute in 
interi, dopodiche' stamparle sullo stdout.  */

int main(void) {
    int ch, value;
    fputs("Write any integer do you want: ", stdout);

    while ((ch = fgetc(stdin)) != EOF && isdigit(ch)) {
        value *= 10;
        value += ch -'0';
        fputc(ch, stdout);
    }

    // Riporta sullo stdin i caratteri che non sono cifre decimali
    ungetc(ch, stdin);

    return(EXIT_SUCCESS);
}
