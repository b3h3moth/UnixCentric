#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAXLEN      256
#define DISPLAY     80
#define PAGE_LENGTH 20

int main(int argc, char *argv[]) {
    char filename[FILENAME_MAX]; // Definito in stdio.h
    FILE *fp;
    size_t len, count, i;
    int lines;
    unsigned char buf[DISPLAY/4-1];

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

    setvbuf(fp, NULL, _IONBF, BUFSIZ);

    while (!feof(fp)) {
        count = fread(buf, sizeof(char), sizeof(buf), fp);
        for (i=0; i<sizeof(buf); ++i) {
            if (i<count)
                printf("%#x", buf[i]);
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
