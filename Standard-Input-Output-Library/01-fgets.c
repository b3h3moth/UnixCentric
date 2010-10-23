#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 516

/*
 * Semplice lettura di un file mediante fgets() e fputs()
 */

int main(int argc, char *argv[])
{
	char *filename = "$HOME/.bashrc";
	FILE *fp;

	char buf[MAX_BUF];

	if ( (fp = fopen(filename, "r")) == NULL) {
		puts("errore");
		abort();
	}

	if ( (fgets(buf, MAX_BUF, fp)) == NULL) {
		puts("fgets err.");
		abort();
	}

	fputs(buf, stdout);
	fclose(fp);

   return(EXIT_SUCCESS);
}
