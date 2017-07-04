#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/inotify.h>

int main(int argc, char *argv[]) {
    int intf_fd;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <pathname,...>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Creazione del file descriptor */
    intf_fd = inotify_init();
    if (intf_fd == -1) {
        fprintf(stderr, "Err: %d inotify_init(); %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
