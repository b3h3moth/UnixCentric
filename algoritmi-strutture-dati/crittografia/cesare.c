#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 1024

int main(int argc, char *argv[])
{
	FILE *f_cleartext;
	FILE *f_ciphertext;
	char *ciphertext = "ciphertext.txt";
	char buffer[MAX_BUF];
	int r_char;
	int i = 0, x = 0;

	if (argc < 2) {
		fprintf(stderr, "Uso: %s <file_da_cifrare>\n", argv[0]);
		abort();
	}

	if ( (f_cleartext = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "%s: Apertura testo in chiaro\n", (char *)strerror(errno));
		abort();
	}

	while ( (r_char = fgetc(f_cleartext)) != EOF) {
		buffer[i] = r_char;
		i++;
	}

	fclose(f_cleartext);

	if ((f_ciphertext = fopen(ciphertext, "w+")) == NULL) {
		fprintf(stderr, "%s: Scrittura testo cifrato\n", (char *)strerror(errno));
		abort();
	}

	for (x=0; x<i; x++) {
		if ( (buffer[x] >= 65 && buffer[x] <= 90) || (buffer[x] >= 97 && buffer[x] <= 122) ) {
			buffer[x] += 3;
		}
		fprintf(f_ciphertext, "%c", buffer[x]);
	}

	fclose(f_ciphertext);

	return(EXIT_SUCCESS);
}
