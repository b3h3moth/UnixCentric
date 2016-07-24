#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int fsize = 0;

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Err. Cannot open image: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Sposta il 'file position indicator' alla fine del file
    fseek(fp, 0, SEEK_END);

    if (ferror(fp)) {
        fprintf(stderr, "Err. fseek() failed.");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fsize = ftell(fp);
    if (fsize == -1) {
        fprintf(stderr, "Err. ftell() failed: %s", strerror(errno));
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    
    printf("The size of \'%s\' is: %d byte\n", argv[1], fsize);

    return(EXIT_SUCCESS);
}
