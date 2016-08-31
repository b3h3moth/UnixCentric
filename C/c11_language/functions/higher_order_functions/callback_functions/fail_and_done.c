#include <stdio.h>
#include <stdlib.h>

// Prototipi
void open_file(char *filename, int(*fail)(int, char*), void(*done)(char*));
int fail(int err_num, char *arg);
void done(char *filename);

/* Lo scopo del programma e' di creare due funzioni callback, fail() e done(),
entrambe utilizzate come argomento della funzione open_file(). */

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    open_file(argv[1], fail, done);

    return(EXIT_SUCCESS);
}

void open_file(char *filename, int(*fail)(int, char*), void(*done)(char*)) {
    FILE *fi;
    fi = fopen(filename, "r");

    if (fi == NULL)
        (*fail)(-11, "Open file");
    else
        (*done)(filename);
}

int fail(int err_num, char *arg) {
    fprintf(stdout, "Err.(%d): %s\n", err_num, arg);
    return(err_num);
}

void done(char *filename) {
    fprintf(stdout, "Opening \'%s\'\n", filename);
}
