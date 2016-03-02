#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    int ch;

    while ((ch = getchar()) != EOF) {
        if ((isprint(ch) || ch == '\n' || ch == '\t' || ch == ' '))
            printf("%03o ", ch);
        else
            printf("\\%03o", ch);
    }

    return(EXIT_SUCCESS);
}
