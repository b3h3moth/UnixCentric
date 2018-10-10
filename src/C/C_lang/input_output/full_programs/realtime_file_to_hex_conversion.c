#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAXLEN      256
#define DISPLAY     80
#define PAGE_LENGTH 20

/* Lo scopo del programma e' di stampare in esadecimale un file ricevuto in
input. Sullo standard output ci sara' prima la versione in hex poi la stringa
di default, per cui sara' diviso in due. */

int main(int argc, char *argv[]) {
    //char filename[FILENAME_MAX]; // Definito in stdio.h
    char *filename;
    FILE *fp;
    size_t len, count, i;
    int lines;
    unsigned char buf[DISPLAY/4-1];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Copia il nome del file ricevuto come argomento nella variabile filename
    filename = malloc(strlen(argv[1]) + 1);
    strcpy(filename, argv[1]);
    len = strlen(filename);
    filename[len] = '\0';

    if ((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Err. opening file, fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    setvbuf(fp, NULL, _IONBF, BUFSIZ);

    while ((count = fread(buf, sizeof(char), sizeof(buf), fp)) != 0) {
        if (ferror(fp)) {
            fprintf(stderr, "File error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        for (i=0; i<sizeof(buf); ++i) {
            if (i<count)
                printf("%02x ", buf[i]);
            else
                printf(" ");
        }
        
        printf("| ");

        for (i=0; i<count; ++i)
            printf("%c", isprint(buf[i]) ? buf[i] : '.');
        printf("\n");

        if (!(++lines % PAGE_LENGTH))
            if (toupper(getchar()) == 'E')
                continue;
    }

    fclose(fp);
    fp = NULL;
    return(EXIT_SUCCESS);
}
