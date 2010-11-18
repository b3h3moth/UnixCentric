#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF			1024
#define CAESAR_SEEK		3
#define LEN_ALPHABET	23

FILE *OpenCleartext(FILE *fp, char *inputfile);

/*
 * Implementazione del cifrario di Cesare, che prevede lo scostamento di tre
 * carratteri in avanti per ogni lettera; e' stato uno dei primi algoritmi
 * crittografici della storia. Saranno modificati solo caratteri alfanumerici,
 * ossia solo numeri e lettere, in tal modo la struttura del documento restera'
 * inalterata, ottenendo peraltro un effetto molto interessante.
 */

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
		exit(EXIT_FAILURE);
	}

	/* Il file di input da cifrare e' fornito come argomento  */
	f_cleartext = OpenCleartext(f_cleartext, argv[1]);

	/* Conteggio righe del file da cifrare (cleartext) */
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
		exit(EXIT_FAILURE);
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
			buf_rows[i] = buf_rows[i] - LEN_ALPHABET; 
		else if ( (buf_rows[i] >= 65 && buf_rows[i] <= 87) || (buf_rows[i] >= 97 && buf_rows[i] <= 120) )
			buf_rows[i] += CAESAR_SEEK;
		else if ( (buf_rows[i] >= 48 && buf_rows[i] <= 54) )
			buf_rows[i] += CAESAR_SEEK;
		else if ( (buf_rows[i] >= 55 && buf_rows[i] <= 57) )
			buf_rows[i] = buf_rows[i] - LEN_ALPHABET;

		fprintf(f_ciphertext, "%c", buf_rows[i]);
	}

	printf("Il file %s e' stato cifrato con successo: \"%s\"\n", argv[1], ciphertext);

	fclose(f_ciphertext);
	free(buf_rows);

	return(EXIT_SUCCESS);
 }

	
FILE *OpenCleartext(FILE *fp, char *inputfile)
{

	if ( (fp = fopen(inputfile, "r")) == NULL) {
		fprintf(stderr, "%s: Apertura testo in chiaro\n", (char *)strerror(errno));
		exit(EXIT_FAILURE);
	}

	return fp;
}
