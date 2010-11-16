#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF	1024
#define CAESAR	3

int main(int argc, char *argv[])
{
	FILE *f_cleartext;
	FILE *f_ciphertext;
	char *ciphertext = "ciphertext.txt";
	char *buf_rows = malloc(sizeof(char) * MAX_BUF);
	int r_char;
	int tot_rows = 0, i = 0;

	/* Si verifica che si fornisca un argomento al programma  */
	if (argc < 2) {
		fprintf(stderr, "Uso: %s <file_da_cifrare>\n", argv[0]);
		abort();
	}

	/* Il file di input da cifrare e' fornito come argomento  */
	if ( (f_cleartext = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "%s: Apertura testo in chiaro\n", (char *)strerror(errno));
		abort();
	}

	/* Conteggio righe del file da cifrare (cleantext) */
	while ( (r_char = fgetc(f_cleartext)) != EOF) {
		tot_rows++;
	}

	/* Se le righe del file da cifrare sono maggiori dell'ampiezza definita di
	 * default, si rialloca lo spazio con la nuova dimensione */
	if (tot_rows > MAX_BUF) {
		buf_rows = realloc(buf_rows, (tot_rows * sizeof(char)));
	}

	/* Si pulisce lo stream per consentire nuovamente di lavorare con il
	 * file di input; si e' preferito non chiudere lo strem precedente */
	fflush(NULL);

	if ( (f_cleartext = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "%s: Apertura testo in chiaro\n", (char *)strerror(errno));
		abort();
	}

	/* Si copia ciascun carattere del file di input (cleartext) nel buf_rows
	 * creato ad hoc */
	while ( (r_char = fgetc(f_cleartext)) != EOF) {
		buf_rows[i++] = r_char;
	}

	fclose(f_cleartext);


	/* Si apre un file in scrittura per contenere il testo cifrato (ciphertext) */
	if ((f_ciphertext = fopen(ciphertext, "w+")) == NULL) {
		fprintf(stderr, "%s: Scrittura testo cifrato\n", (char *)strerror(errno));
		abort();
	}

	/* Si modificano solo i caratteri ASCII; ciascun carattere pertanto sara'
	 * spostato di 3 elementi in avanti; cosi' come il cifrario di Cesare
	 * contempla, quando si giungera' alle ultime letere, si ripartira'
	 * dall'inizio. */
	for (i=0; i<tot_rows; i++) {
		if ( (buf_rows[i] >= 88 && buf_rows[i] <= 90) || (buf_rows[i] >= 120 && buf_rows[i] <= 122) )
			buf_rows[i] = buf_rows[i] - 23; 
		else if ( (buf_rows[i] >= 65 && buf_rows[i] <= 87) || (buf_rows[i] >= 97 && buf_rows[i] <= 120) )
			buf_rows[i] += CAESAR;
	
		fprintf(f_ciphertext, "%c", buf_rows[i]);
	}

	printf("Il file %s e' stato cifrato con successo\n", argv[1]);

	fclose(f_ciphertext);
	free(buf_rows);

	return(EXIT_SUCCESS);
 }
