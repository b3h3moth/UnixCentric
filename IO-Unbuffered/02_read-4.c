#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUF 30

/* Read input data and print out them */

int main(void) {
    char buf[MAX_BUF + 1];  /* Remember to add the newline */
    ssize_t num_read;       /* ssize_t is the right choice for portability */
    
    if (read(STDIN_FILENO, buf, MAX_BUF) == -1) {
        fprintf(stderr, "Err. reading file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Data: %s\n", buf);

    return(EXIT_SUCCESS);
}
