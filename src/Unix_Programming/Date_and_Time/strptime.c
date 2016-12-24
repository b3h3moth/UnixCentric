#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum { LEN = 255 };

/* Lo scopo del programma e' di convertire una stringa di data in formato 
'struct tm' mediante strptime(), successivamente salvarla in un buffer con la 
funzione strftime() */

int main(void) {
    struct tm tm;
    char buf[LEN];

    memset(&tm, 0, sizeof(struct tm));
    
    strptime("2016-12-24 20:30:05", "%Y-%m-%d %H:%M:%S", &tm);
    strftime(buf, sizeof(buf), "%d/%b/%Y %H:%M", &tm);
    
    printf("%s\n", buf);

    exit(EXIT_SUCCESS);
}
