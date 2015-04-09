#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <a><b><c>\n", argv[0]);
        exi(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
