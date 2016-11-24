#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

/* Lo scopo del programma e' di mostrare come un file 'riservato' possa essere
letto da un programma con i setuid bits attivati. Pertanto dopo la fase di 
compilazione, sia i permessi sia il proprietario dell'esseguibile dovranno 
essere modificati attivando i setuid bits, utilizzando chmod e chown. */

int main(int argc, char *argv[]) {
    FILE *fp;
    struct passwd *user;
	int c;

	if (argc != 2) {
        fprintf(stderr, "Usage: %s <login name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Salva la struttura passwd dell'account fornito come argomento
    user = getpwnam(argv[1]);
	
    // Imposta l'Effective user ID a 0, per la lettura del file
    setuid(0);

    printf("Real: %ld Effective: %ld\n", (long)getuid(), (long)geteuid());

	fp = fopen("/etc/shadow", "r");

	if (fp == NULL) { 
		fprintf(stderr,"Err. Can't open file.");
        exit(EXIT_FAILURE);
	}
		
    while((c = fgetc(fp)) != EOF)
        fputc(c, stdout);
		
    fclose(fp);

    // Riporta l'Effective user ID allo stato iniziale
    setuid(user->pw_uid);

    printf("Real: %ld Effective: %ld\n", (long)getuid(), (long)geteuid());

	return(EXIT_SUCCESS);
}
