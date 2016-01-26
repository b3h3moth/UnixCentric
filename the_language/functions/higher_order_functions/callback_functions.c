#include <stdio.h>
#include <stdlib.h>

// Prototipi
void open_file(char *filename, int(*fail)(int, char*), void(*done)(char*));
int fail(int err_num, char *arg);
void done(char *filename);

/* Lo scopo del programma e' di creare due funzioni callback, fail() e done(),
entrambe utilizzate come argomento della funzione open_file(). */

int main(int argc, char *argv[]) {

    open_file(argv[1], fail, done);

    return(EXIT_SUCCESS);
}

void open_file(char *filename, int(*fail)(int, char*), void(*done)(char*)) {
    FILE *fi;
    fi = fopen(filename, "r");

    if (fi == NULL)
        (*fail)(-1, "Opening %s file");
    else
        (*done)(filename);
}

int fail(int err_num, char *arg) {
    fprintf(stdout, "Err. %d - %s\n", err_num, arg);
    return(err_num);
}

void done(char *filename) {
    fprintf(stdout, "The file \'%s\' is readable\n", filename);
}
