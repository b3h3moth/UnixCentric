#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    int ch;

    while ((ch = getchar()) != EOF) {
        if (isascii(ch) && (isprint(ch) || ch == '\n' || ch == '\t' || ch == ' '))
            fputc(ch, stdout);
        else
            printf("\\%03o", ch);
    }

    return(EXIT_SUCCESS);
}
