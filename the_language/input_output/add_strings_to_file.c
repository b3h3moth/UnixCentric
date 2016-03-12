#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LEN 31

int main(void) {
    FILE *fp;
    char buf[MAX_LEN];
    char *filename = "data.txt";

    if ((fp = fopen(filename, "a+")) == NULL) {
        fprintf(stderr, "Err. fopen(); %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Enter strings to add to \'%s\' (press ? to terminate)\n", filename);
    // Ricezione delle stringhe in input, e scrittura delle stesse sul file
    while ((fscanf(stdin, "%30s", buf) == 1) && (buf[0] != '?'))
        fprintf(fp, "%s\n", buf);

    fclose(fp);

    return(EXIT_SUCCESS);
}
