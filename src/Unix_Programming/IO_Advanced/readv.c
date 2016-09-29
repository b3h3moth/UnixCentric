#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>

enum { NBUF = 3 };

int main(void) {
    struct iovec iov[NBUF] = {0};
    const char *const *buf[] = {0};

    return(EXIT_SUCCESS);
}
