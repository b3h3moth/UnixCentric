#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LEN 80

int main(int argc, char *argv[]) {
    FILE *fp;
    unsigned long last;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Sposta il file pointer alla fine del file, salvando la posizione
    if (fseek(fp, 0, SEEK_END) != -1)
        last = ftell(fp);


    return(EXIT_SUCCESS);
}
