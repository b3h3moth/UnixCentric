#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Lo scopo del programma e' di ottenere informazioni su un file system montato.
Il device relativo al file siystem viene fornito in input. */

int main(int argc, char *argv[]) {
    char *pathname = NULL;
    size_t len = 0;

    if (argc != 2) {
        fprintf(stdout, "Usage: %s 'pathname'\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    len = strlen(argv[1]) + 1;
    pathname = malloc(len * sizeof(char));
    strncpy(pathname, argv[1], len);

    return(EXIT_SUCCESS);
}
