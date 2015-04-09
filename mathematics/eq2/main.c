#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int a,b,c = 0;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <a><b><c>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((a = strtol(argv[1], NULL, 10)) != 0 ) {
        fprintf(stderr, "Err.: a argument %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
