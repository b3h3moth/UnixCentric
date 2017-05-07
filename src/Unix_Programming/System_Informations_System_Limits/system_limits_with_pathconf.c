#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>

static void pr_pathconf(char *msg, char *path, int name);

/* Lo scopo del programma e' di fornire diverse informazioni circa le
"limitazioni" del sistema in uso. Da notare le costanti passate alle funzioni,
quelle che iniziano con _PC sono passate a pathconf() o fpathconf().*/

int main (int argc, char *argv[]) {

    if (argc != 2) {
    	printf ("Usage: %s <dirname>", argv[0]);
	    exit(EXIT_FAILURE);
    }

    pr_pathconf("MAX_CANON                 =", "/dev/tty", _PC_MAX_CANON);
    pr_pathconf("MAX_INPUT                 =", "/dev/tty", _PC_MAX_INPUT);
    pr_pathconf("_POSIX_VDISABLE           =", "/dev/tty", _PC_VDISABLE);
    pr_pathconf("LINK_MAX                  =", argv[1], _PC_LINK_MAX);
    pr_pathconf("NAME_MAX                  =", argv[1], _PC_NAME_MAX);
    pr_pathconf("PATH_MAX                  =", argv[1], _PC_PATH_MAX);
    pr_pathconf("PIPE_BUF                  =", argv[1], _PC_PIPE_BUF);
    pr_pathconf("_POSIX_NO_TRUNC           =", argv[1], _PC_NO_TRUNC);
    pr_pathconf("_POSIX_CHOWN_RESTRICTED   =", argv[1], _PC_CHOWN_RESTRICTED);

    exit(EXIT_SUCCESS);
}

static void pr_pathconf(char *msg, char *path, int name) {
    long val;
    fputs (msg, stdout);
    errno = 0;

    if ((val = pathconf (path, name)) < 0) {
    	if (errno != 0) {
	        perror ("pathconf error");
	        exit(EXIT_FAILURE);
	}

        fputs (" (no limit)\n", stdout);
    } else
    	printf (" %ld\n", val);
}
