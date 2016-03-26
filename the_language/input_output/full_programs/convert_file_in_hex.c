#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

int main(void) {
    char *filename[FILENAME_MAX]; // Definito in stdio.h
    FILE *fp;
    size_t len;

    if (argc == 1) {
        // Inserimento del nome del file
        fputs("Enter filename: ", stdout);
        fgets(filename, MAXLEN, stdin);

        len = strlen(filename);

        // Rimuove la new-line finale
        if (filename[len-1] == '\n')
            filename[len-1] = '\0';
    } else
        strcpy(filename, argv[1]);

    return(EXIT_SUCCESS);
}
