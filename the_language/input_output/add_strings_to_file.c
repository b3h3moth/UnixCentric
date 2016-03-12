#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LEN 31

int main(void) {
    FILE *fp;
    char buf[MAX_LEN];
    char *filename = "data.txt";

    if ((fp = fopen(filename, "a+")) == NULL) {
        fprintf(stderr, "Err. fopen(); %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Enter strings to add to \'%s\' (press ? to terminate)\n", filename);
    // Ricezione delle stringhe in input, e scrittura delle stesse sul file
    while ((fscanf(stdin, "%30s", buf) == 1) && (buf[0] != '?'))
        fprintf(fp, "%s\n", buf);


    /* Ci si sposta all'inizio del file, e poiche' il file stesso e' stato
    aperto in modalita' 'a+' (append) leggera' tutto cio' che e' stato scritto
    nelle varie esecuzione del programma */
    fseek(fp, 0L, SEEK_SET);

    while (fscanf(fp, "%s", buf) != -1)
        fputs(buf, stdout);

    fclose(fp);
    return(EXIT_SUCCESS);
}
