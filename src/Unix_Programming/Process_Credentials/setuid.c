#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

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
