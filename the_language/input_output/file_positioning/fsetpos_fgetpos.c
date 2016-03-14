#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* Lo scopo del programma e' di simulare mediante fgetpos() e fsetpos() il
concetto di SEEK_SET e SEEK_END associato a fseek(). */

int main(int argc, char *argv[]) {
    FILE *fp;
    fpos_t pos_beg, pos_end;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
   
    // Imposta pos_beg all'inizio del file, ovvero SEE_SET
    if (fgetpos(fp, &pos_beg) != 0) {
        fprintf(stderr, "Err. fgetpos(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Imposta pos_end alla fine del file, ovvero SEE_END
    while (feof(fp)) {
        if (fgetpos(fp, &pos_end) != 0) {
            fprintf(stderr, "Err. fgetpos(), %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    // Ora il file poin

    fsetpos(fp, &pos_end);


    fclose(fp);

    return(EXIT_SUCCESS);
}
