#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/inotify.h>

int main(int argc, char *argv[]) {
    int intf_fd, i, wd;

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

    /* Aggiunta dei file da monitorare */
    for (i=1; i<argc; i++) {
        /* Sono monitorati tutti gli eventi riguardanti l'input */
        wd = inotify_add_watch(intf_fd, argv[i], IN_ALL_EVENTS);
        if (wd == -1) {
            fprintf(stderr, "Usage: %s <pathname,...>\n", argv[0]);
            exit(EXIT_FAILURE);
        }

        printf("Wathing %s using watch descriptor (wd) %d\n", argv[i], wd);
    }

    return(EXIT_SUCCESS);
}
