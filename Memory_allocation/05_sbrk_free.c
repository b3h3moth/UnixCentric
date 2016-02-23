#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_ALLOC 1000000

int main(int argc, char *argv[]) {
    char *ptr[MAX_SIZE_ALLOC];
    int free_step, free_max, block_size, n_alloc, i;

    if (argc < 3 || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, "Usage: %s num-allocs block-size [step [min [max]]]\n",\
                argv[0]);
        exit(EXIT_FAILURE);
    }

    n_alloc = strtol(argv[1], NULL, 10);

    if (n_alloc > MAX_SIZE_ALLOC) {
        fprintf(stderr, "Err. num-alloc > %d\n", MAX_SIZE_ALLOC);
        exit(EXIT_FAILURE);
    }
    
    return(EXIT_SUCCESS);
}
