#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LEN 80

main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    
    return(EXIT_SUCCESS);
}
