#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

/* Lo scopo del programma e' di mostrare come un file 'riservato' possa essere
letto da un programma con i setuid bits attivati. Pertanto dopo la fase di 
compilazione, sia i permessi sia il proprietario dell'esseguibile devono essere 
modificati attivando i setuid bits, utilizzando chmod e chown. */

int main(int argc, char *argv[]) {
    FILE *fp;
	int c;
    struct passwd *user;

    user = getpwnam(argv[1]);

	if (argc != 2) {
        fprintf(stderr, "Usage: %s <user ID>.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
		
    setuid(user->pw_uid);

	if ((fp = fopen("/etc/shadow", "r")) != NULL) {
		while((c = getc(fp)) != EOF)
			putchar(c);
		fclose(fp);
	} else {
		fprintf(stderr,"Err. Can't open file.");
        exit(EXIT_FAILURE);
	}

	return(EXIT_SUCCESS);
}
