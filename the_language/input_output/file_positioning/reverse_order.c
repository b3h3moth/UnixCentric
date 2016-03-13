#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LEN 80

int main(int argc, char *argv[]) {
    FILE *fp;
    int ch;
    unsigned long last;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Sposta il file pointer alla fine del file, salva inoltre la posizione
    del file pointer stesso, ovvero il numero dei byte del file */
    if (fseek(fp, 0, SEEK_END) != -1)
        last = ftell(fp);

    for (long i=1; i<last; i++)
        if (fseek(fp, -i, SEEK_END) != -1)
            putchar(ch = getc(fp));

    return(EXIT_SUCCESS);
}
