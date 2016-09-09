#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

enum { MAX_BUF = 512 };

/* La funzione 'int setvbuf(FILE *stream, char *buf, int mode, size_t size)' 
definisce la bufferizzazione dello stream. */

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    struct stat st;

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
      fprintf(stderr, "Open file failed: %s\n", strerror(errno));
      return 1;
    }

    if (fstat(fileno(fp), &st) == -1) {
      fprintf(stderr, "stat file failed: %s\n", strerror(errno));
      return 1;
    }

    printf("BUFFER SIZE: %d | Preferred block size: %ld\n", \
            MAX_BUF, st.st_blksize);

   return EXIT_SUCCESS;
}
