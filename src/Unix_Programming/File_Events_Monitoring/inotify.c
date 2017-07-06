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
    if (j->mask & IN_OPEN) printf("IN_OPEN ");
    if (j->mask & IN_ACCESS) printf("IN_ACCESS ");
    if (j->mask & IN_ATTRIB) printf("IN_ATTRIB ");
    if (j->mask & IN_CLOSE_NOWRITE) printf("IN_CLOSE_NOWRITE ");
    if (j->mask & IN_CLOSE_WRITE) printf("IN_CLOSE_WRITE ");
    if (j->mask & IN_CREATE) printf("IN_CREATE ");
    if (j->mask & IN_DELETE) printf("IN_DELETE ");
    if (j->mask & IN_DELETE_SELF) printf("IN_DELETE_SELF ");
    if (j->mask & IN_ISDIR) printf("IN_ISDIR ");
    if (j->mask & IN_MODIFY) printf("IN_ISDIR ");
    if (j->mask & IN_MOVED_TO) printf("IN_MOVED_TO ");
    if (j->mask & IN_MOVED_FROM) printf("IN_MOVED_FROM ");
    if (j->mask & IN_MOVE_SELF) printf("IN_MOVE_SELF ");
    printf("\n");

    if (j->len > 0)
        printf(" name:%s\n", j->name);
}

int main(int argc, char *argv[]) {
    int intf_fd, i, wd;
    ssize_t nread;
    //char buf[BUF_LEN]__attribute__ ((aligned(__alignof__(struct inotify_event))));
    char buf[512 * (sizeof(struct inotify_event) + 13)];

    char *p;
    struct inotify_event *event;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <pathname,...>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Creazione del file descriptor.
    La funzine inotify_init() inizializza un'istanza inotify e restituisce un
    file descriptor mediante il quale saranno effettuate le operazioni di
    notifica. Al file descriptor peraltro non sono associati file, esso
    piuttosto si occupa della notifica degli eventi posti in osservazione.
    E' consentito monitorare sia file sia directory. */
    intf_fd = inotify_init();
    if (intf_fd == -1) {
        fprintf(stderr, "Err: %d inotify_init(); %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Il file o i file ottenuti dalla command-line sono aggiunti alla lista
    watch list, associata ad una coda, mediante la funzione
    inotify_add_watch(). */
    for (i=1; i<argc; i++) {
        /* Ciascun file ottenuto come argomento dalla command-line sara'
        monitorato su specifici eventi di input. */
        wd = inotify_add_watch(intf_fd, argv[i], IN_ALL_EVENTS);
        if (wd == -1) {
            fprintf(stderr, "Usage: %s <pathname,...>\n", argv[0]);
            exit(EXIT_FAILURE);
        }

        printf("Wathing %s using watch descriptor (wd) %d\n", argv[i], wd);
    }

    while (1) {
        /* Lettura di un buffer di eventi dal file descriptor inotify */
        nread = read(intf_fd, buf, BUF_LEN);
        if (nread == 0) {
            fprintf(stderr, "returned 0 from inotify read(), it's not good\n");
            exit(EXIT_FAILURE);
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
