#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

enum { BUF_MAX = 64 };

int main(int argc, char *argv[]) {
    // Inizializza a 0 buf (si sarebbe potuto utilizzare memset())
    char buf[BUF_MAX] = {0};
    FILE *fin;

    for (int i=1; i<argc; i++) {
        if ((fin = fopen(argv[i], "r"))) {
            while (fgets(buf, BUF_MAX, fin)) {
                fputs(buf, stdout);
            }
            fclose(fin);
        } else {
            fprintf(stderr, "Err. fopen(); %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    return(EXIT_SUCCESS);
}
