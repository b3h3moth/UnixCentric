#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* Lo scopo del programma e' di aprire un file e leggere alcuni byte da diversi
offset. Si utilizzeranno le funzioni portabili fsetpos() e fgetpos(). */

int main(int argc, char *argv[]) {
    FILE *fp;
    fpos_t pos;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    int offset = fgetpos(fp, &file_pos);
    printf("%d\n", offset);

    fclose(fp);

    return(EXIT_SUCCESS);
}
