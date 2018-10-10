#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

unsigned long count[UCHAR_MAX+1];

/* Lo scopo del programma e' di visualizzare la frequenza dei byte.
Uso: ./a.out < file */

int main(void) {
    int c;

    while ((c = getchar()) != EOF) 
        count[c]++;

    for (c=0; c<= UCHAR_MAX; c++)
        if (count[c] != 0)
            printf("%.2x %c %lu\n", c, isprint(c) ? c : '-', count[c]);

    return(EXIT_SUCCESS);
}
