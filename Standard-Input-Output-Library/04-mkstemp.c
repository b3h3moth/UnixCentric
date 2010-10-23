#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUF 64

/*
 * Utilizzo della funzione mkstemp()
 * Prototipo: int mkstemp(char *template);
 *
 * Il parametro e' un puntatore ad una stringa, ossia un puntatore a char, tale
 * stringa sara' utilizzata come modello per il percorso temporaneo; da notare
 * che gli ultimi 6 caratteri dovranno essere necessariamente composto in questa
 * maniera: "XXXXXX", dopodiche' saranno sovrascritte affinche' il percorso
 * risulti unico.
 */

int main(int argc, char *argv[])
{
	/* Path del file temporaneo */
	char temp_path[MAX_BUF];
	/* Descrittore del file */
	int fd = -1;
	/* File temporaneo */
	FILE *f_tmp;

	/* Template della stringa */
	char *template = "/tmp/00-XXXXXX";

	/* Si copia il template nel path temporaneo */
	strcpy(temp_path, template);

	if ((fd = mkstemp(temp_path)) < 0) {
		fprintf(stderr, "%s: Creazione file temp.\n", (char *)strerror(errno));
		exit(EXIT_FAILURE);
	}

	/* In output il nome del file creato */
	printf("Temp file :%s\n", temp_path);

	/* Si apre il file in lettura e scrittura */
	if ( (f_tmp = fdopen(fd, "w+")) == NULL) {
		fprintf(stderr, "%s: Scrittura su file", (char *)strerror(errno));
		exit(EXIT_SUCCESS);
	}

	fprintf(f_tmp, "Scrittura sul file %s\n", temp_path);
	fclose(f_tmp);

   return(EXIT_SUCCESS);
}
