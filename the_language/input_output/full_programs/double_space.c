#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Function Prototypes
void dbl_spacing(FILE *fin, FILE *fout);
void usage(char *prog_name);

/* Lo scopo del programma e' di raddoppiare la spaziatura in un file ricevuto
in input, salvandone una copia */

int main(int argc, char *argv[]) {
    FILE *fin, *fout;

    if (argc != 3)
        usage(argv[0]);

    if ((fin = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Err. opening input file, %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if ((fout = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Err. opening output file, %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}

// Realizza la doppia spaziatura nel file 'fin',  salva il tutto in 'fout'
void dbl_spacing(FILE *fin, FILE *fout) {
}

// Informazioni circa il programma in uso
void usage(char *prog_name) {
    fprintf(stdout, "Usage: %s <input file> <output file>\n", prog_name);
}
