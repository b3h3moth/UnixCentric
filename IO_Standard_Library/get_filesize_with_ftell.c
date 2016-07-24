#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    int fsize = 0;

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Err. Cannot open image: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
