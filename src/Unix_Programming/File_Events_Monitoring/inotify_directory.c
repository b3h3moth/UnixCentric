#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/inotify.h>

#define EVENT_SIZE  (sizeof(struct inotify_event))
#define BUF_LEN     (1024 * (EVENT_SIZE + 16))
#define EVENTS      (IN_MODIFY | IN_CREATE | IN_DELETE)

int main(int argc, char *argv[]){
    int i = 0, fd, wd;
    ssize_t length;
	char buf[BUF_LEN];
    struct inotify_event *event;
    struct stat sb;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dirname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (stat(argv[1], &sb) == -1) {
        fprintf(stderr, "Err.: %d stat() %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (!S_ISDIR(sb.st_mode)) {
        fprintf(stderr, "'%s' is not a directory, plese fix.\n", argv[1]);
        exit(EXIT_FAILURE);
    }


	fd = inotify_init();
	if (fd < 0) {
        fprintf(stderr, "Err.: %d inotify_init; %s\n", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}

	wd = inotify_add_watch(fd, argv[1], EVENTS);
    if (wd <= 0) {
        fprintf(stderr, "Err.: %d watch list %s\n", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}

	length = read(fd, buf, BUF_LEN);
	if (length < 0) {
        fprintf(stderr, "Err.: %d read(); %s\n", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}

	while (i < length) {
        event = (struct inotify_event *) buf + i;

		if (event->len) {
			if (event->mask & IN_CREATE) {
				if (event->mask & IN_ISDIR) {
					printf("The directory \'%s\' was created.\n", event->name);
				} else
                    printf("The file \'%s\' was created.\n", event->name);
			} else if (event->mask & IN_DELETE) {
				if (event->mask & IN_ISDIR) {
					printf("The directory \'%s\' was deleted.\n", event->name);
				} else
					printf("The file \'%s\' was deleted.\n", event->name);
			} else if (event->mask & IN_MODIFY) {
				if (event->mask & IN_ISDIR) {
                    printf("The directory \'%s\' was modified.\n", event->name);
				} else
					printf("The file \'%s\' was modified.\n", event->name);
			}
		}

		i += EVENT_SIZE + event->len;
	}

	//inotify_rm_watch(fd, wd);
	close(fd);

	exit(EXIT_SUCCESS);
}
