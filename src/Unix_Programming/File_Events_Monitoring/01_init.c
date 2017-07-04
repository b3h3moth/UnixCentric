#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <linux/limits.h>
#include <unistd.h>
#include <sys/inotify.h>

#define BUF_LEN (10 * (sizeof(struct inotify_event) + NAME_MAX + 1))

static void display_events(struct inotify_event *j) {
    printf(" wd:%2d; ", j->wd);

    if (j->cookie > 0)
        printf(" cookie:%4d; ", j->cookie);

    printf("mask: ");
    if (j->mask & IN_ACCESS) printf("IN_ACCESS ");
    if (j->mask & IN_ATTRIB) printf("IN_ATTRIB ");
    if (j->mask & IN_CLOSE_NOWRITE) printf("IN_CLOSE_NOWRITE ");
    if (j->mask & IN_CLOSE_WRITE) printf("IN_CLOSE_WRITE ");
    if (j->mask & IN_CREATE) printf("IN_CREATE ");
    if (j->mask & IN_DELETE) printf("IN_DELETE ");
    if (j->mask & IN_DELETE_SELF) printf("IN_DELETE_SELF ");
    if (j->mask & IN_IGNORED) printf("IN_IGNORED ");
    if (j->mask & IN_ISDIR) printf("IN_ISDIR ");
    if (j->mask & IN_MODIFY) printf("IN_ISDIR ");
    if (j->mask & IN_MOVE_SELF) printf("IN_MOVE_SELF ");
    if (j->mask & IN_MOVED_FROM) printf("IN_MOVED_FROM ");
    if (j->mask & IN_MOVED_TO) printf("IN_MOVED_TO ");
    if (j->mask & IN_OPEN) printf("IN_OPEN ");
    if (j->mask & IN_Q_OVERFLOW) printf("IN_Q_OVERFLOW ");
    if (j->mask & IN_UNMOUNT) printf("IN_UNMOUNT ");

    if (j->len > 0)
        printf(" name:%s\n", j->name);
}

int main(int argc, char *argv[]) {
    int intf_fd, i, wd;
    ssize_t nread;
    char buf[BUF_LEN];
    char *p;
    struct inotify_event *event;

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

    /* Il file o i file ottenuti dalla command-line sono aggiunti alla lista
    dei file da monitorare */
    for (i=1; i<argc; i++) {
        /* Sono monitorati tutti gli eventi possibili riguardanti l'input */
        wd = inotify_add_watch(intf_fd, argv[i], IN_ALL_EVENTS);
        if (wd == -1) {
            fprintf(stderr, "Usage: %s <pathname,...>\n", argv[0]);
            exit(EXIT_FAILURE);
        }

        printf("Wathing %s using watch descriptor (wd) %d\n", argv[i], wd);
    }

    for (;;) {
        /* Lettura di un buffer di eventi dal file descriptor inotify */
        nread = read(intf_fd, buf, BUF_LEN);
        if (nread == -1) {
            fprintf(stderr, "returned 0 from inotify read(), it's not good\n");
        }

        if (nread == -1) {
            fprintf(stderr, "Err. %d read(); %s\n", errno, strerror(errno));
            exit(EXIT_FAILURE);
        }

        printf("Read %ld bytes from inotify fd\n", (long)nread);

        /* Chiamata della funzione  display_events() per visualizzare il
        contenuto di ciascun 'struct inotify_event' all'interno del buffer. */
        for(p = buf; p < (buf + nread); ) {
            event = (struct inotify_event *) p;
            display_events(event);

            p += sizeof(struct inotify_event) + event->len;
        }
    }

    return(EXIT_SUCCESS);
}
