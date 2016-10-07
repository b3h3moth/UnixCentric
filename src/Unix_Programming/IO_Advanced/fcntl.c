#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/* Lo scopo del programma e' di fornire informazioni sul file descriptor aperto
mediante la funzione fcntl()

$ ./a.out 0 < /dev/fd/0
$ ./a.out 1 < /dev/fd/0
*/

int main(int argc, char *argv[]) {
    int val;
    
    if (argc < 2) {
    	fprintf(stderr, "Usage: %s <N file descriptor>\n", argv[0]);
	    exit(EXIT_FAILURE);
    }

    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
    	fprintf(stderr, "Err.(%s) fcntl() failed\n", strerror(errno));
	    exit(EXIT_FAILURE);
    }

    switch (val & O_ACCMODE) {
    	case O_RDONLY:
	    printf("read only");
	    break;

	case O_WRONLY:
	    printf("write only");
	    break;

	case O_RDWR:
	    printf("read write");
	    break;

	default:
	    printf("access mode unknow");
	    exit(EXIT_FAILURE);
    }

    if (val & O_APPEND)
    	printf(", append");

    if (val & O_NONBLOCK)
    	printf(", non-blocking");

#if defined(O_SYNC)
    if (val & O_SYNC)
    	printf(", async writing");
#endif
    printf("\n");

    return(EXIT_SUCCESS);
}
