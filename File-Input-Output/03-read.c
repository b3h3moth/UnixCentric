#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUF 4096

int main(int argc, char *argv[], char *envp[]) 
{
    char finput[] = "/etc/fstab";
    int fd;
    char *buffer[MAX_BUF];

    /*
     * fprintf(stdout, "%s : (%d byte)\n", finput, strlen(finput));
     * Equivalente a:
     * write(fileno(stdout), finput, strlen(finput));
     *
     * La write() ben piu' veloce ed efficiente
     */


    if ( (fd = open(finput, O_RDONLY)) == -1) {
		fprintf(stdout,"%s", "Impossibile aprire il file");
		exit(EXIT_FAILURE);
	} else {
		read(fd, buffer, MAX_BUF);
		printf("%s", buffer);
	}

	close(fd);

    return(EXIT_SUCCESS);
}
