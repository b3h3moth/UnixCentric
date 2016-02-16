#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define MAX_STR 64
#define RECORDS 10

struct rec {
    int id;
    char string[MAX_STR];
};

typedef struct rec Record;

int main(int argc, char *argv[]) {
    Record record, *fmap;
    FILE *fp;
    int fd;

    if ((fp = fopen(argv[1], "w+")) == NULL) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Inizializzazione e scrittura su disco dei record
    for (int i=0; i<RECORDS; i++) {
        record.id = i;
        sprintf(record.string, "record: '%d'\n", i);
        fwrite(record.string, strlen(record.string), 1, fp);
    }
    fclose(fp);

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        fprintf(stderr, "Err.(%d) open() - %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fmap = mmap(0, RECORDS * sizeof(record), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (fmap == MAP_FAILED) {
        fprintf(stderr, "Err.(%d) mmap() - %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    int n, n2;
    char buf, buf2[4096];

    while ((n = read(fd, &buf, 1)) > 0) {
        write(1, &buf, n);
    }

    /* Legge da memoria e inserisce tutto nel buffer
     if ((n2 = read(fd,buf2, 4096)) < 0)
         exit (-1);
     if (write (STDOUT_FILENO, buf2, n2) < 0)
         exit (-1);
     */

    return(EXIT_SUCCESS);
}
