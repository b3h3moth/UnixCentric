#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int val = 10;
    FILE *fp;

    if ((fp = fopen("data.bin", "ab+")) == NULL) {
        fprintf(stderr, "Err. open stream with fopen()\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Scrittuta di un intero in un file

    return(EXIT_SUCCESS);
}
