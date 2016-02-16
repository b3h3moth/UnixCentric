#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define MAX_STR 64
#define RECORDS 100

typedef struct {
    int id;
    char title[MAX_STR];
} Record;

int main(int argc, char *argv[]) {
    Record record, *mapped;
    int fin, fout;
    FILE *fp;

    if ((fp = fopen(argv[1], "w+")) == NULL) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    return(EXIT_SUCCESS);
}
