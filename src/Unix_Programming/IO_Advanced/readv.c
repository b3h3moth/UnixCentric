#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

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

    fd = open("bob_marley_songs.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if (fd == -1) {
        fprintf(stderr, "Err. open() failed: %d\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
