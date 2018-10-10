#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXBUF  256

// Function Prototypes
int find_str(FILE *fp, const char *str);

/* Lo scopo del programma e' di cercare, mediante la funzione find_str(), 
tutte le linee del file, e stamparle sullo stdout, in cui ci dovesse essere una
corrispondenza con la stringa fornita alla funzione stessa */

int main(int argc, char *argv[]) {
    FILE *fp;
    size_t nstr;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename, string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == 0) {
        fprintf(stderr, "Err. opening stream, fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if ((nstr = find_str(fp, argv[2])) > 0)
        printf("\nFind \'%d\' string/s in \'%s\'\n", nstr, argv[1]);
    else
        printf("Doesn't find \'%s\' in \'%s\'\n", argv[2], argv[1]);

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
