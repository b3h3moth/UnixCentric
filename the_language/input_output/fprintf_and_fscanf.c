#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define LEN 50

/* Lo scopo del programma e' di scrivere degli interi in un file, dopodiche'
leggere il file scritto e invertire i numeri */

int main(int argc, char *argv[]) {
    FILE *fp;
    int data[LEN], val;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "w")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<LEN; i++) {
        val = rand() % 1000;
        fprintf(fp, "%2d %3d\n", i, val);
    }
    
    return(EXIT_SUCCESS);
}
