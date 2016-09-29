#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

enum { NBUF = 3 };

int main(void) {
    struct iovec iov[NBUF];
    ssize_t nbyte;
    int fd, i;
    char *buf[] = {
        "No woman No cry.\n",
        "Redemption Song.\n",
        "Rastaman vibration.\n"
    };

    fd = open("bob_marley_songs.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if (fd == -1) {
        fprintf(stderr, "Err. open() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Riempimento della struttura iov
    for (i=0; i<NBUF; i++) {
        iov[i].iov_base = buf[i];
        iov[i].iov_len = strlen(buf[i]) + 1;
    }

    // Scrittura del file
    nbyte = writev(fd, iov, NBUF);
    if (nbyte == -1) {
        fprintf(stderr, "Err. writev() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
