#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUF  256

int find_str(FILE *fp, const char *str);

/* Lo scopo del programma e' di cercare, mediante la funzione find_str(), 
tutte le linee del file, e stamparle sullo stdout, in cui ci dovesse essere una
corrispondenza con la stringa fornita alla funzione stessa */

int main(void) {
    FILE *fp;

    return(EXIT_SUCCESS);
}

int find_str(FILE *fp, const char *str) {
    char buf[MAXBUF] = "";
    int count = 0;

    if (fp == NULL || str == NULL)
        return(-1);
    else
        rewind(fp); // 'File position inidicator' impostato all'inizio del file

    // Stampa le linee al'interno delle quali vi e' 'str'
    while (fgets(buf, MAXBUF, fp) != NULL)
        if (strstr(buf, str) != NULL) {
            ++count;
            fputs(buf, stdout);
        }

    if (feof(fp))
        return count;
    else
        return(-1);
}
