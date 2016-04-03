#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

// Stampa l'ora di accesso del file ricevuto in input

int main(int argc, char *argv[]) {
    struct stat stbuf;
    
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (stat(argv[1], &stbuf) == -1) {
        fprintf(stderr, "Err.: fsize %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Last status change: %s\n", ctime(&stbuf.st_ctime));

    exit(EXIT_SUCCESS);
}
