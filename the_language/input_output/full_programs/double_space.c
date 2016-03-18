#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void dbl_spacing(FILE *fin, FILE *fout);
void usage(char *prog_name);

/* Lo scopo del programma e' di raddoppiare la spaziatura in un file ricevuto
in input, salvandone una copia */

int main(int argc, char *argv[]) {
    FILE *fin, *fout;

    if (argc != 3)
        usage(argv[0]);

    return(EXIT_SUCCESS);
}

// Realizza la doppia spaziatura nel file 'fin',  salva il tutto in 'fout'
void dbl_spacing(FILE *fin, FILE *fout) {
}

// Informazioni circa il programma in uso
void usage(char *prog_name) {
    fprintf(stdout, "Usage: %s <input file> <output file>\n", prog_name);
}
