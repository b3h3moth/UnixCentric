#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 72

/* Lo scopo del programma e' di aprire un file e leggere alcuni byte da diversi
offset. Si utilizzeranno le funzioni portabili fsetpos() e fgetpos(). */

int main(int argc, char *argv[]) {
    FILE *fp;
    fpos_t pos;
    char buf[MAX_BUF];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Lettura di MAX_BUF byte dal file e salvati in buf
    if (!feof(fp)) {
        fread(buf, sizeof(char), MAX_BUF, fp);
        buf[MAX_BUF-1] = '\0';

        if (fgetpos(fp, &pos) != 0) {
            fprintf(stderr, "Err. fgetpos(), %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
    
    printf("%s\n", buf);

    fclose(fp);

    return(EXIT_SUCCESS);
}
