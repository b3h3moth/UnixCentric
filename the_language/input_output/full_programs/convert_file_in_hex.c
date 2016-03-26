#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAXLEN  256

int main(int argc, char *argv[]) {
    char filename[FILENAME_MAX]; // Definito in stdio.h
    FILE *fp;
    size_t len;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Inserimento del nome del file
    fputs("Enter filename: ", stdout);
    fgets(filename, MAXLEN, stdin);
    
    len = strlen(filename);

    // Rimuove la new-line finale
    if (filename[len-1] == '\n')
        filename[len-1] = '\0';

    if ((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Err. opening file, fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    setvbuf(fp, NULL, _IOFBF, BUFSIZ);

    return(EXIT_SUCCESS);
}
