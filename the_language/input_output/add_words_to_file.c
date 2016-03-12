#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LEN 31

int main(void) {
    FILE *fp;
    char words[MAX_LEN];
    char *filename = "data.txt";

    if ((fp = fopen(filename, "a+")) == NULL) {
        fprintf(sdterr, "Err. fopen(); %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return(EXIT_SUCCESS);
}
