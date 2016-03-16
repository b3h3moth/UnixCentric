#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;

    fp = fopen(argv[1], "r");
    if (fp != NULL) {
        fprintf(stderr, "Err. fopen()\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    fclose(fp);
    return(EXIT_SUCCESS);
}
