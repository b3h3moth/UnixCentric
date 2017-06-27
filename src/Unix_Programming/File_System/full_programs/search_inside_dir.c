#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

/* Lo scopo del programma e' di cercare, all'interno della directory ottenuta
in input, ciascun file maggiore di 1MB. */

int  main(int argc, char *argv[]) {
	int             dir_fd, fd;
	DIR             *dir;
    struct stat 	statbuf;
	struct dirent   *dirp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dirname>\n", argv[0]);
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
		if ((fd = openat(dir_fd, dirp->d_name, O_RDONLY)) == -1) {
            fprintf(stderr, "Err.:%d openat(); %s", errno, strerror(errno));
			continue;
		}
		if (fstat(fd, &statbuf) == 0 && statbuf.st_size > (1024 * 1024)) {
			/* elemento trovato */
			printf("%s: %jdK\n", dirp->d_name,
			       (intmax_t) (statbuf.st_size / 1024));
		}
		close(fd);
	}
	closedir(dir);
    
    return(EXIT_SUCCESS);
}
