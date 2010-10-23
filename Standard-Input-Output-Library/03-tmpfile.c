#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

#define MAX_BUF 512

/*

Prototipo:
	FILE *tmpfile(void);

Note:
	Utilizzo di tmpfile.
	La caratteristica della funzione tmpfile() e' che il file temporaneo creato
	sara' automaticamente eliminato alla chiusura del programma

*/

int main(int argc, char *argv[])
{
	char buf[MAX_BUF];

	FILE *ftmp;

	/* Crea il file temporaneo mediante tmpfile() */
	if ( (ftmp = tmpfile()) == NULL)
			fprintf(stderr, "%s :generazione file temp.", (char *)strerror(errno));

	/* Scrive nel file temp */
	fputs("tmpfile() crea un file binario temporaneo\n", ftmp);

	/* Torna il puntatore all'inizio del file */
	rewind(ftmp);

	/* Legge dal file temp */
	if ( (fgets(buf, MAX_BUF, ftmp)) == NULL)
			fprintf(stderr, "%s lettura da file temp.", (char *)strerror(errno));
	fputs(buf, stdout);

	/* Chiusura del file */
	fclose(ftmp);

   return(EXIT_SUCCESS);
}
