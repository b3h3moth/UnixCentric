#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define FILE_PERMS (S_IRUSR | S_IWUSR |S_IRGRP | S_IWGRP |S_IROTH | S_IWOTH)

int main(int argc, char *argv[]) {
    int fd, p;      // File descriptor, parametro
    size_t len;
    ssize_t num_read, num_written;
    char *buf;

    if (argc < 3 || strncmp(argv[1], "--help", 6)  == 0) {
        fprintf(stderr, "Usage: %s <filename> [r|R|w!s]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Apertura del file su cui lavorare
    if ((fd = open(argv[1], O_RDWR | O_CREAT, FILE_PERMS)) == -1) {
        fprintf(stderr, "Err. open(%s): %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (p = 2; p < argc; p++) {
        switch(argv[p][0]) {
            // Visualizza il file-offset corrente in byte, in testo
            case 'r': 
            // Visualizza il file-offset corrente in byte, in esadecimale
            case 'R':
                // lunghezza del buffer
                len = atoi(argv[1], NULL, 10);
                
                // Allocazione della memoria per il buffer
                if ((buf = malloc(len)) == NULL) {
                    fprintf(stderr, "Err. malloc()\n");
                    exit(EXIT_FAILURE);
                }

                if ((num_read = read(fd, buf, len)) == -1) {
                    fprintf(stderr, "Err. read()\n");
                    exit(EXIT_FAILURE);
                }

                if (num_read == 0) {
                    printf("%s: EOF\n", argv[p]);
                } else {
                    printf("%s: ", argv[p]);


    return(EXIT_SUCCESS);
}
