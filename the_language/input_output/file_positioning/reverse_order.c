#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 80

main(int argc, char *argv[]) {
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    return(EXIT_SUCCESS);
}
