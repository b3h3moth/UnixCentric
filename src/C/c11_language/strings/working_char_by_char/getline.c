#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>


/*
 * Calcola e stampa su stdout la lunghezza di ciascuna riga del file puntato da
 * filename.
 */

int main (void)
{
	FILE *fp;
	char *filename = "/etc/passwd";
	char *setmode = "r";
	char *line = NULL;
	size_t len = 0;
	unsigned int read;

	if ( (fp = fopen (filename, setmode)) == NULL) {
		fprintf(stderr, "%s: Open file\n", filename);
		exit(EXIT_FAILURE);
	}

	/* Legge dallo stream fp una linea, archivia il risultato in line */
	while ((read = getline(&line, &len, fp)) != -1)
		printf ("(len: %u) %s", read, line);

	free (line);
	fclose(fp);

	return (EXIT_SUCCESS);
}
