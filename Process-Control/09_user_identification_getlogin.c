#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
HEADER    : <unistd.h>
PROTOTYPE : char *getlogin(void);
SEMANTICS : La funzione getlogin() server per ottenere il login name
RETURNS   : Un puntatore alla stringa con il login name in caso di successo, 
            NULL in caso di errore
--------------------------------------------------------------------------------
Sui sistemi unix-like, poiche' uno stesso utente puo' avere diversi login-name,
ossia voci nel file /etc/passwd, inoltre puo' essere collegato a piu' di un 
terminale, questa funzione lo identifica e fornisce un puntatore alla stringa
relativa al login-name in uso.
*/

int main(int argc, char *argv[]) {
    char *login_name;
    
    if ((login_name = getlogin()) == NULL) {
    	fprintf(stderr, "Err.(%s) getlogin() failed\n", strerror(errno));
	exit(EXIT_FAILURE);
    }

    printf("login name: %s\n", login_name);

    return(EXIT_SUCCESS);
}
