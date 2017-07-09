#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> /* strerror() */

/* La funzione strerror() - char *strerror(int errnum); - ritorna un puntatore
ad una stringa che descrive il codice di errore ottenuto dall'argomento
'errnum'. */

/* Lo scopo del programma e' il tentativo di aprire il file /etc/passwd in
scrittura, che se eseguito come utente causera' un errore, tale errore sara'
descritto dalla funzione strerror(). */

int main(void) {
	FILE *passdb;

	if ( (passdb = fopen("/etc/passwd", "w")) == NULL) {
		fprintf(stderr, "EACCES %d: %s\n", EACCES, strerror(EACCES));
		exit(EXIT_FAILURE);
	}

  return(EXIT_SUCCESS);
}
