#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

enum { MAX_BUF = 512 };

/* La funzione 'int setvbuf(FILE *stream, char *buf, int mode, size_t size)' 
definisce la bufferizzazione dello stream.

Lo scopo del programma e' di cambiare la dimensione del buffer, utilizzando
la grandezza appropriata mediante specifiche informazioni sullo status del
file in lettura. */

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    struct stat st;
    int ch;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
      fprintf(stderr, "Open file failed: %s\n", strerror(errno));
      return 1;
    }

    if (fstat(fileno(fp), &st) == -1) {
      fprintf(stderr, "stat file failed: %s\n", strerror(errno));
      return 1;
    }

    printf("BUFFER SIZE: %d | Preferred I/O block size: %ld\n", \
            MAX_BUF, st.st_blksize);

    // Settaggio del buffering 
    if (setvbuf(fp, NULL, _IOFBF, st.st_blksize) != 0) {
      fprintf(stderr, "Setup buffering failed: %s\n", strerror(errno));
      return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
        fputc(ch, stdout);

    fclose(fp);

   return EXIT_SUCCESS;
}
