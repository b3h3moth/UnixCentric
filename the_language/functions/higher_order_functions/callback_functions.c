#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEM_SIZE   10

// Prototipi
void open_file(FILE *stream, char *filename, int(*fail)(int, char*));
int fail(int err_num, char *arg);
void access_granted(char *filename);

int main(int argc, char *argv[]) {
    FILE *fi;
    
    open_file(fi, argv[1], &fail);

    return(EXIT_SUCCESS);
}

void open_file(FILE *stream, char *filename, int(*fail)(int, char*)) {
    stream = fopen(filename, "r");

    if (stream == NULL)
        (*fail)(-1, "Opening %s file");
    else
        (*access_granted)(filename);
}

int fail(int err_num, char *arg) {
    fprintf(stdout, "Err. %d - %s\n", err_num, arg);
    return(err_num);
}

void access_granted(char *filename) {
    fprintf(stdout, "The file \'%s\' is readable\n", filename);
}
