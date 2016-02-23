#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 512

static const char fname[] = "/etc/passwd";

int main(void) {
    char buf[BUF_SIZE];
    FILE *fp;

    if ((fp = fopen(fname, "r"))) {
        printf("%s is open.\n", fname);

        // Impostazione del buffer a 'BUF_SIZE', svuotarlo ad ogni 'new line'
        if (setvbuf(fp, buf, _IOLBF, BUF_SIZE) != 0) {
            fprintf(stderr, "Err. setvbuf() %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    return(EXIT_SUCCESS);
}
