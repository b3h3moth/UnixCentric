#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>

/* Lo scopo del programma e' di verificare il risultato delle chiamate alle
funzioni dirname() e basename() */

int main(int argc, char *argv[]) {
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <full path>\n", argv[0]);
        fprintf(stderr, "dirname: [], basename: ()\n");
        exit(EXIT_FAILURE);
    }

    for (i=1; i<argc; i++)
        printf("[%s](%s)\n", dirname(argv[i]), basename(argv[i]));

    exit(EXIT_SUCCESS);
}
