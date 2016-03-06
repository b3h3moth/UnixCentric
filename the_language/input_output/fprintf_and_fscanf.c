#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define LEN 50

/* Lo scopo del programma e' di scrivere degli interi in un file, dopodiche'
leggere dal file e inizializzare un array di LEN elementi con i valori
invertiti. Infine scrivere sul file precedentemente aperto l'array con
gli elementi invertiti. */

int main(int argc, char *argv[]) {
    FILE *fp;
    int data[LEN], val, j;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Writing file
    if ((fp = fopen(argv[1], "w")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<LEN; i++) {
        val = rand() % 1000;
        fprintf(fp, "%2d %3d\n", i, val);
    }

    fclose(fp);

    // Reading file
    if ((fp = fopen(argv[1], "r+")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (int i=1; i<=LEN; i++) {
        fscanf(fp, "%2d %3d", &j, &val);
        data[LEN-i] = val;
    }

    fprintf(fp, "\n-----[ Array elements inversion ]-----\n");
    for (int i=1; i<=LEN; i++) {
        fprintf(fp, "%2d %3d\n", i, data[i]);
    }

    fclose(fp);
    
    return(EXIT_SUCCESS);
}
