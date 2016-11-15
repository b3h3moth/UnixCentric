#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <error.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int c;

	if (argc == 1)
		setuid(1000);		/* need to replace 500 with real uid */

	if ((fp = fopen("/etc/shadow", "r")) != NULL) {
		while((c = getc(fp)) != EOF)
			putchar(c);
		fclose(fp);
	} else {
		fprintf(stderr,"Can't open file.");
	}

	return(EXIT_SUCCESS);
}
