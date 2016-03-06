#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define LEN 50

/* Lo scopo del programma e' di scrivere degli interi in un file, dopodiche'
leggere il file scritto e invertire i numeri */

int main(void) {
    FILE *fp;
    int data[LEN];

    if ((fp = fopen(argv[1], "w")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
