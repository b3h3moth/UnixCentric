#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errrno.h>

#define PAGE_SIZE 22

// Function prototype
FILE *openfile(char *file, char *mode);

/* Lo scopo del programma e' di leggere l'input una pagina alla volta, la
dimensione della pagina, in righe naturalmente, e' definita da PAGE_SIZE */

int main(int argc, char *argv[]) {
    char *program_name;
    FILE *fp;

    openfile(argv[1], "r");

    return(EXIT_SUCCESS);
}

FILE *openfile(char *file, char *mode) {
    FILE *fp;

    fp = fopen(file, mode);

    if (fp != NULL)
        return fp;
    else {
        fprintf(stderr, "Err. fopen() %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}
