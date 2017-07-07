#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

int main(int argc, char *argv[]){
    int length, i = 0;
	int fd;
	int wd;
	char buffer[BUF_LEN];

	fd = inotify_init();

	if (fd < 0) {
        fprintf(stderr, "Err.: %d inotify_init; %s\n", errno, strerror(errno));
		EXIT(EXIT_FAILURE);
	}

	wd = inotify_add_watch(fd, "/home/strike",
			       IN_MODIFY | IN_CREATE | IN_DELETE);
	length = read(fd, buffer, BUF_LEN);

	if (length < 0) {
		perror("read");
	}

	while (i < length) {
		struct inotify_event *event =
		    (struct inotify_event *)&buffer[i];
		if (event->len) {
			if (event->mask & IN_CREATE) {
				if (event->mask & IN_ISDIR) {
					printf
					    ("The directory %s was created.\n",
					     event->name);
				} else {
					printf("The file %s was created.\n",
					       event->name);
				}
			} else if (event->mask & IN_DELETE) {
				if (event->mask & IN_ISDIR) {
					printf
					    ("The directory %s was deleted.\n",
					     event->name);
				} else {
					printf("The file %s was deleted.\n",
					       event->name);
				}
			} else if (event->mask & IN_MODIFY) {
				if (event->mask & IN_ISDIR) {
					printf
					    ("The directory %s was modified.\n",
					     event->name);
				} else {
					printf("The file %s was modified.\n",
					       event->name);
				}
			}
		}
		i += EVENT_SIZE + event->len;
	}

	inotify_rm_watch(fd, wd);
	close(fd);

	exit(0);
}
