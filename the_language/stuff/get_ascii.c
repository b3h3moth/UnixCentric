#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024
#define MIN_SIZE 10

void get_ascii(char *name, FILE *f_in);

int main(void) {
    return(EXIT_SUCCESS);
}

void get_ascii(char *name, FILE *f_in) {
    int c, i;
    char buf[BUF_SIZE];

    do {
        for (i=0; (c = fgetc(f_in)) != EOF) {
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
