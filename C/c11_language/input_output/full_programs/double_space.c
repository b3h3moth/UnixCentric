#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Function Prototypes
void dbl_spacing(FILE *in, FILE *out);
void usage(char *prog_name);

/* Lo scopo del programma e' di raddoppiare la spaziatura di in un file
ricevuto in input, salvandone una copia */

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

    dbl_spacing(fin, fout);

    fclose(fin);
    fclose(fout);

    return(EXIT_SUCCESS);
}

// Realizza la doppia spaziatura nel file 'fin',  salva il tutto in 'fout'
void dbl_spacing(FILE *in, FILE *out) {
    int ch;

    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);

        if (ch == ' ')
            fputs("   ", out);
    }
}

// Informazioni circa il programma in uso
void usage(char *prog_name) {
    fprintf(stdout, "Usage: %s <input file> <output file>\n", prog_name);
}
