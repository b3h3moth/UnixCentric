#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 3 || strncmp(argv[1], "--help", 6) == 0) {
        fprintf(stderr, "Usage: %s r|R|w|s\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
