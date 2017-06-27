#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/stat.h>

int  main(int argc, char *argv[]) {
	int             dir_fd, fd;
	DIR             *dir;
    struct stat 	statbuf;
	struct dirent   *dirp;

    if (argc != 2) {
        fprint(stderr, "Usage: %s <dirname>\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Apre la directory specificata dal file descriptor ritornato dalla 
    funzione open() */
	if ((dir = fdopendir((dir_fd = open(argv[1], O_RDONLY)))) == NULL) {
		fprintf(stderr, "Err.:%d open(); %s", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}

	while ((dirp = readdir(dir)) != NULL) {
		if (dirp->d_name[0] == '.')
			continue;
		
        /*  In questo contesto potrebbe verificarsi una race condition qualora
        il file dovesse essere rinominato tra l'apertura della open() e della
        readdir(). */

        /* Si utilizza la funzione openat() per determinare il file nella
        ddirectory corrente */
		if ((ffd = openat(dfd, dp->d_name, O_RDONLY)) == -1) {
			perror(dp->d_name);
			continue;
		}
		if (fstat(ffd, &statbuf) == 0 && statbuf.st_size > (1024 * 1024)) {
			/* found it ... */
			printf("%s: %jdK\n", dp->d_name,
			       (intmax_t) (statbuf.st_size / 1024));
		}
		close(ffd);
	}
	closedir(d);
	//note this implicitly closes dfd
		return 0;
}
