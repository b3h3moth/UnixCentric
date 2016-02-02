#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUF_SIZE 1024
#define MIN_SIZE 10

void get_ascii(char *name, FILE *f_in);

int main(int argc, char *argv[]) {
    int i;
    FILE *f_in;

    if (argc == 1) {
        fprintf(stderr, "Usage: %s <filename/s>\n", argv[0]);
        exit(EXIT_FAILURE);
    } 

    for (i=1; i<argc; i++) {
        if ((f_in = fopen(argv[i], "rb")) == NULL) {
            fprintf(stderr, "Err. open file\n");
            exit(EXIT_FAILURE);
        } else {
            get_ascii(argv[i], f_in);
            fclose(f_in);
        }
    }

    return(EXIT_SUCCESS);
}

void get_ascii(char *name, FILE *f_in) {
    int c, i;
    char buf[BUF_SIZE];

    do {
        for (i=0; (c = fgetc(f_in)) != EOF; ) {
            if (!isprint(c))
                break;

            buf[i++] = c;

            if (i >= BUF_SIZE)
                break;
        }

        // Stampa solo se e' sufficientemente lungo
        if (i >= MIN_SIZE)
            printf("%s:%.*s\n", name, i, buf);
    } while (c != EOF);
}
