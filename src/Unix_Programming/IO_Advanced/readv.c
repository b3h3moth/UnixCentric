#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>

enum { NBUF = 3 };

int main(void) {
    struct iovec iov[NBUF] = {0};
    ssize_t nread;
    int fd, i;
    const char *const *buf[] = {
        "No woman No cry.\n",
        "Redemption Song.\n",
        "Rastaman vibration.\n"
    };

    return(EXIT_SUCCESS);
}
