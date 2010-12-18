#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void fsize(char *name);

int main(int argc, char *argv[]) {
    fsize("/home");

    return(EXIT_SUCCESS);
}

void fsize(char *name) {
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
		fprintf(stderr, "Err: '%s'\n", name);
		return(EXIT_FAILURE);
    }

	/* Mostra varie caratteristiche del file system, nel caso specifico la 
	 * directory /home passata come parametro alla funzione fsize();  */

	if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
	/*  printf("%8ld %s\n", stbuf.st_dev, name);	 ID of device containing file */
		printf("%8ld %s\n", stbuf.st_ino, name);	/* inode number */
		printf("%8ld %s\n", stbuf.st_mode, name); 	/* protection */
		printf("%8ld %s\n", stbuf.st_nlink, name);	/* number of hard links */
		printf("%8ld %s\n", stbuf.st_uid, name);	/* user ID of owner */
		printf("%8ld %s\n", stbuf.st_gid, name);	/* Group ID of owner */
	/*	printf("%8ld %s\n", stbuf.st_rdev, name);	device ID (if special file) */
		printf("%8ld %s\n", stbuf.st_size, name);	/* total size, in bytes */
		printf("%8ld %s\n", stbuf.st_blksize, name); /* blocksize for file system I/O */
		printf("%8ld %s\n", stbuf.st_blksize, name); /* blocksize for file system I/O */
		printf("%8ld %s\n", stbuf.st_blocks, name);	/* number of 512B blocks allocated */
		printf("%8ld %s\n", stbuf.st_atime, name);	/* time of last access */
		printf("%8ld %s\n", stbuf.st_mtime, name);	/* time of last modification */
		printf("%8ld %s\n", stbuf.st_ctime, name);	/* time of last status change */
	}
}
